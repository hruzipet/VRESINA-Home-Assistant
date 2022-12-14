"""
Support for The Shelly Wifi switch.

Save this file inside ".homeassistant/custom_components/switch" (create the folders if not present) and restart HASS.

usage example:

switch:
  - platform: shelly
    switches:
      shelly_switch:
        path: /relay/0 (optional, defaults to /relay/0)
        host: 10.0.0.219
        username: admin
        password: admin
        
Path is optional and defaults to '/relay/0'. If you have the 2-relay Shelly for the second one use /relay/1.
Username & Password are optional. Use only if you have enabled authentication from the shelly web interface.
"""
import logging

import requests
import voluptuous as vol

from homeassistant.components.switch import SwitchDevice, PLATFORM_SCHEMA
from homeassistant.const import (
    CONF_HOST, CONF_NAME, CONF_PATH, CONF_USERNAME, CONF_PASSWORD,
    CONF_SWITCHES)
import homeassistant.helpers.config_validation as cv

_LOGGER = logging.getLogger(__name__)

DEFAULT_PATH = "/relay/0"

SWITCH_SCHEMA = vol.Schema({
    vol.Required(CONF_HOST): cv.string,
    vol.Optional(CONF_NAME): cv.string,
    vol.Optional(CONF_PATH, default=DEFAULT_PATH): cv.string,
    vol.Optional(CONF_USERNAME): cv.string,
    vol.Optional(CONF_PASSWORD): cv.string,
})

PLATFORM_SCHEMA = PLATFORM_SCHEMA.extend({
    vol.Required(CONF_SWITCHES): vol.Schema({cv.slug: SWITCH_SCHEMA}),
})


def setup_platform(hass, config, add_devices_callback, discovery_info=None):
    """Set up Shelly Wifi switches."""
    switches = config.get('switches', {})
    devices = []

    for dev_name, properties in switches.items():
        devices.append(
            ShellySwitch(
                hass,
                properties.get(CONF_NAME, dev_name),
                properties.get(CONF_HOST, None),
                properties.get(CONF_PATH, DEFAULT_PATH),
                properties.get(CONF_USERNAME, None),
                properties.get(CONF_PASSWORD)))

    add_devices_callback(devices)


class ShellySwitch(SwitchDevice):
    """Representation of a Shelly Wifi switch."""

    def __init__(self, hass, name, host, path, user, passwd):
        """Initialize the device."""
        self._hass = hass
        self._name = name
        self._state = False
        self._url = 'http://{}{}'.format(host, path)
        if user is not None:
            self._auth = (user, passwd)
        else:
            self._auth = None

    def _switch(self, newstate):
        """Switch on or off."""
        _LOGGER.info("Switching to state: %s", newstate)

        try:
            req = requests.get('{}?turn={}'.format(self._url, newstate),
                               auth=self._auth, timeout=5)
            result = req.json()['ison']
            if newstate == 'on':
                return result == True
            else:
                return result == False
        except requests.RequestException as error:
            _LOGGER.error("Switching failed: " + error)

    def _query_state(self):
        """Query switch state."""
        _LOGGER.info("Querying state from: %s", self._url)

        try:
            req = requests.get('{}'.format(self._url),
                               auth=self._auth, timeout=5)
            return req.json()['ison'] == True
        except requests.RequestException as error:
            _LOGGER.error("State query failed: " + error)

    @property
    def should_poll(self):
        """Return the polling state."""
        return True

    @property
    def name(self):
        """Return the name of the switch."""
        return self._name

    @property
    def is_on(self):
        """Return true if device is on."""
        return self._state

    def update(self):
        """Update device state."""
        self._state = self._query_state()

    def turn_on(self, **kwargs):
        """Turn the device on."""
        if self._switch('on'):
            self._state = True

    def turn_off(self, **kwargs):
        """Turn the device off."""
        if self._switch('off'):
            self._state = False