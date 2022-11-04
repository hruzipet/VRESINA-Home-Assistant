// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.h"
using namespace esphome;
using std::isnan;
using std::min;
using std::max;
using namespace button;
logger::Logger *logger_logger;
web_server_base::WebServerBase *web_server_base_webserverbase;
captive_portal::CaptivePortal *captive_portal_captiveportal;
wifi::WiFiComponent *wifi_wificomponent;
mdns::MDNSComponent *mdns_mdnscomponent;
ota::OTAComponent *ota_otacomponent;
api::APIServer *api_apiserver;
using namespace api;
web_server::WebServer *web_server_webserver;
using namespace sensor;
using namespace json;
preferences::IntervalSyncer *preferences_intervalsyncer;
improv_serial::ImprovSerialComponent *improv_serial_improvserialcomponent;
esp32_ble_tracker::ESP32BLETracker *esp32_ble_tracker_esp32bletracker;
bluetooth_proxy::BluetoothProxy *bluetooth_proxy_bluetoothproxy;
safe_mode::SafeModeButton *safe_mode_safemodebutton;
dallas::DallasComponent *dallas_dallascomponent;
esp32::ArduinoInternalGPIOPin *esp32_arduinointernalgpiopin;
dallas::DallasTemperatureSensor *dallas_dallastemperaturesensor;
atc_mithermometer::ATCMiThermometer *atc_mithermometer_atcmithermometer;
sensor::Sensor *sensor_sensor;
sensor::Sensor *sensor_sensor_2;
sensor::Sensor *sensor_sensor_3;
sensor::Sensor *sensor_sensor_4;
sensor::Sensor *sensor_sensor_5;
#define yield() esphome::yield()
#define millis() esphome::millis()
#define micros() esphome::micros()
#define delay(x) esphome::delay(x)
#define delayMicroseconds(x) esphome::delayMicroseconds(x)
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="

void setup() {
  // ========== AUTO GENERATED CODE BEGIN ===========
  // async_tcp:
  //   {}
  // esphome:
  //   name: esp32-vresina-1p
  //   build_path: .esphome/build/esp32-vresina-1p
  //   platformio_options: {}
  //   includes: []
  //   libraries: []
  //   name_add_mac_suffix: false
  App.pre_setup("esp32-vresina-1p", __DATE__ ", " __TIME__, false);
  // button:
  // logger:
  //   id: logger_logger
  //   baud_rate: 115200
  //   tx_buffer_size: 512
  //   deassert_rts_dtr: false
  //   hardware_uart: UART0
  //   level: DEBUG
  //   logs: {}
  logger_logger = new logger::Logger(115200, 512, logger::UART_SELECTION_UART0);
  logger_logger->pre_setup();
  logger_logger->set_component_source("logger");
  App.register_component(logger_logger);
  // web_server_base:
  //   id: web_server_base_webserverbase
  web_server_base_webserverbase = new web_server_base::WebServerBase();
  web_server_base_webserverbase->set_component_source("web_server_base");
  App.register_component(web_server_base_webserverbase);
  // captive_portal:
  //   id: captive_portal_captiveportal
  //   web_server_base_id: web_server_base_webserverbase
  captive_portal_captiveportal = new captive_portal::CaptivePortal(web_server_base_webserverbase);
  captive_portal_captiveportal->set_component_source("captive_portal");
  App.register_component(captive_portal_captiveportal);
  // wifi:
  //   networks:
  //   - ssid: !secret 'wifi_ssid'
  //     password: !secret 'wifi_password'
  //     id: wifi_wifiap
  //     priority: 0.0
  //   - ssid: !secret 'wifi_ssid_2'
  //     password: !secret 'wifi_password2'
  //     id: wifi_wifiap_2
  //     priority: 0.0
  //   use_address: 192.168.2.175
  //   id: wifi_wificomponent
  //   domain: .local
  //   reboot_timeout: 15min
  //   power_save_mode: LIGHT
  //   fast_connect: false
  wifi_wificomponent = new wifi::WiFiComponent();
  wifi_wificomponent->set_use_address("192.168.2.175");
  wifi::WiFiAP wifi_wifiap = wifi::WiFiAP();
  wifi_wifiap.set_ssid("Hajenka_net");
  wifi_wifiap.set_password("Ulesa2010!");
  wifi_wifiap.set_priority(0.0f);
  wifi_wificomponent->add_sta(wifi_wifiap);
  wifi::WiFiAP wifi_wifiap_2 = wifi::WiFiAP();
  wifi_wifiap_2.set_ssid("lm1-2");
  wifi_wifiap_2.set_password("JedeToDobre2011-2022");
  wifi_wifiap_2.set_priority(0.0f);
  wifi_wificomponent->add_sta(wifi_wifiap_2);
  wifi_wificomponent->set_reboot_timeout(900000);
  wifi_wificomponent->set_power_save_mode(wifi::WIFI_POWER_SAVE_LIGHT);
  wifi_wificomponent->set_fast_connect(false);
  wifi_wificomponent->set_component_source("wifi");
  App.register_component(wifi_wificomponent);
  // mdns:
  //   id: mdns_mdnscomponent
  //   disabled: false
  mdns_mdnscomponent = new mdns::MDNSComponent();
  mdns_mdnscomponent->set_component_source("mdns");
  App.register_component(mdns_mdnscomponent);
  // ota:
  //   password: 8147176ea43fedb00ff6a75f80bd3f7e
  //   id: ota_otacomponent
  //   safe_mode: true
  //   port: 3232
  //   reboot_timeout: 5min
  //   num_attempts: 10
  ota_otacomponent = new ota::OTAComponent();
  ota_otacomponent->set_port(3232);
  ota_otacomponent->set_auth_password("8147176ea43fedb00ff6a75f80bd3f7e");
  ota_otacomponent->set_component_source("ota");
  App.register_component(ota_otacomponent);
  if (ota_otacomponent->should_enter_safe_mode(10, 300000)) return;
  // api:
  //   id: api_apiserver
  //   port: 6053
  //   password: ''
  //   reboot_timeout: 15min
  api_apiserver = new api::APIServer();
  api_apiserver->set_component_source("api");
  App.register_component(api_apiserver);
  api_apiserver->set_port(6053);
  api_apiserver->set_password("");
  api_apiserver->set_reboot_timeout(900000);
  // web_server:
  //   port: 80
  //   id: web_server_webserver
  //   version: 2
  //   web_server_base_id: web_server_base_webserverbase
  //   include_internal: false
  //   ota: true
  //   css_url: ''
  //   js_url: https:oi.esphome.io/v2/www.js
  web_server_webserver = new web_server::WebServer(web_server_base_webserverbase);
  web_server_webserver->set_component_source("web_server");
  App.register_component(web_server_webserver);
  web_server_base_webserverbase->set_port(80);
  web_server_webserver->set_css_url("");
  web_server_webserver->set_js_url("https://oi.esphome.io/v2/www.js");
  web_server_webserver->set_allow_ota(true);
  web_server_webserver->set_include_internal(false);
  // sensor:
  // json:
  //   {}
  // esp32:
  //   board: esp32cam
  //   framework:
  //     version: 1.0.6
  //     source: ~3.10006.0
  //     platform_version: platformio/espressif32 @ 3.5.0
  //     type: arduino
  //   variant: ESP32
  // preferences:
  //   id: preferences_intervalsyncer
  //   flash_write_interval: 60s
  preferences_intervalsyncer = new preferences::IntervalSyncer();
  preferences_intervalsyncer->set_write_interval(60000);
  preferences_intervalsyncer->set_component_source("preferences");
  App.register_component(preferences_intervalsyncer);
  // improv_serial:
  //   id: improv_serial_improvserialcomponent
  improv_serial_improvserialcomponent = new improv_serial::ImprovSerialComponent();
  improv_serial_improvserialcomponent->set_component_source("improv_serial");
  App.register_component(improv_serial_improvserialcomponent);
  // dashboard_import:
  //   package_import_url: github:esphome/bluetooth-proxies/esp32-generic.yaml@main
  dashboard_import::set_package_import_url("github://esphome/bluetooth-proxies/esp32-generic.yaml@main");
  // esp32_ble_tracker:
  //   scan_parameters:
  //     interval: 1100ms
  //     window: 1100ms
  //     active: true
  //     duration: 5min
  //     continuous: true
  //   id: esp32_ble_tracker_esp32bletracker
  esp32_ble_tracker_esp32bletracker = new esp32_ble_tracker::ESP32BLETracker();
  esp32_ble_tracker_esp32bletracker->set_component_source("esp32_ble_tracker");
  App.register_component(esp32_ble_tracker_esp32bletracker);
  esp32_ble_tracker_esp32bletracker->set_scan_duration(300);
  esp32_ble_tracker_esp32bletracker->set_scan_interval(1760);
  esp32_ble_tracker_esp32bletracker->set_scan_window(1760);
  esp32_ble_tracker_esp32bletracker->set_scan_active(true);
  esp32_ble_tracker_esp32bletracker->set_scan_continuous(true);
  // bluetooth_proxy:
  //   id: bluetooth_proxy_bluetoothproxy
  //   esp32_ble_id: esp32_ble_tracker_esp32bletracker
  bluetooth_proxy_bluetoothproxy = new bluetooth_proxy::BluetoothProxy();
  bluetooth_proxy_bluetoothproxy->set_component_source("bluetooth_proxy");
  App.register_component(bluetooth_proxy_bluetoothproxy);
  esp32_ble_tracker_esp32bletracker->register_listener(bluetooth_proxy_bluetoothproxy);
  // button.safe_mode:
  //   platform: safe_mode
  //   name: Safe Mode Boot
  //   entity_category: diagnostic
  //   disabled_by_default: false
  //   icon: mdi:restart-alert
  //   device_class: restart
  //   id: safe_mode_safemodebutton
  //   ota: ota_otacomponent
  safe_mode_safemodebutton = new safe_mode::SafeModeButton();
  safe_mode_safemodebutton->set_component_source("safe_mode.button");
  App.register_component(safe_mode_safemodebutton);
  App.register_button(safe_mode_safemodebutton);
  safe_mode_safemodebutton->set_name("Safe Mode Boot");
  safe_mode_safemodebutton->set_disabled_by_default(false);
  safe_mode_safemodebutton->set_icon("mdi:restart-alert");
  safe_mode_safemodebutton->set_entity_category(::ENTITY_CATEGORY_DIAGNOSTIC);
  safe_mode_safemodebutton->set_device_class("restart");
  safe_mode_safemodebutton->set_ota(ota_otacomponent);
  // dallas:
  //   pin:
  //     number: 2
  //     mode:
  //       output: true
  //       input: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     inverted: false
  //     id: esp32_arduinointernalgpiopin
  //   update_interval: 10s
  //   id: dallas_dallascomponent
  dallas_dallascomponent = new dallas::DallasComponent();
  dallas_dallascomponent->set_update_interval(10000);
  dallas_dallascomponent->set_component_source("dallas");
  App.register_component(dallas_dallascomponent);
  esp32_arduinointernalgpiopin = new esp32::ArduinoInternalGPIOPin();
  esp32_arduinointernalgpiopin->set_pin(2);
  esp32_arduinointernalgpiopin->set_inverted(false);
  esp32_arduinointernalgpiopin->set_flags(gpio::Flags::FLAG_OUTPUT);
  dallas_dallascomponent->set_pin(esp32_arduinointernalgpiopin);
  // sensor.dallas:
  //   platform: dallas
  //   address: 0x710000065CF35628
  //   name: ESP2Temp
  //   disabled_by_default: false
  //   force_update: false
  //   id: dallas_dallastemperaturesensor
  //   unit_of_measurement: °C
  //   accuracy_decimals: 1
  //   device_class: temperature
  //   state_class: measurement
  //   dallas_id: dallas_dallascomponent
  //   resolution: 12
  dallas_dallastemperaturesensor = new dallas::DallasTemperatureSensor();
  App.register_sensor(dallas_dallastemperaturesensor);
  dallas_dallastemperaturesensor->set_name("ESP2Temp");
  dallas_dallastemperaturesensor->set_disabled_by_default(false);
  dallas_dallastemperaturesensor->set_device_class("temperature");
  dallas_dallastemperaturesensor->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  dallas_dallastemperaturesensor->set_unit_of_measurement("\302\260C");
  dallas_dallastemperaturesensor->set_accuracy_decimals(1);
  dallas_dallastemperaturesensor->set_force_update(false);
  dallas_dallastemperaturesensor->set_address(0x710000065CF35628);
  dallas_dallastemperaturesensor->set_resolution(12);
  dallas_dallastemperaturesensor->set_parent(dallas_dallascomponent);
  dallas_dallascomponent->register_sensor(dallas_dallastemperaturesensor);
  // sensor.atc_mithermometer:
  //   platform: atc_mithermometer
  //   mac_address: A4:C1:38:E8:DF:96
  //   temperature:
  //     name: ATC Temperature
  //     disabled_by_default: false
  //     id: sensor_sensor
  //     force_update: false
  //     unit_of_measurement: °C
  //     accuracy_decimals: 1
  //     device_class: temperature
  //     state_class: measurement
  //   humidity:
  //     name: ATC Humidity
  //     disabled_by_default: false
  //     id: sensor_sensor_2
  //     force_update: false
  //     unit_of_measurement: '%'
  //     accuracy_decimals: 0
  //     device_class: humidity
  //     state_class: measurement
  //   battery_level:
  //     name: ATC Battery-Level
  //     disabled_by_default: false
  //     id: sensor_sensor_3
  //     force_update: false
  //     unit_of_measurement: '%'
  //     accuracy_decimals: 0
  //     device_class: battery
  //     state_class: measurement
  //     entity_category: diagnostic
  //   battery_voltage:
  //     name: ATC Battery-Voltage
  //     disabled_by_default: false
  //     id: sensor_sensor_4
  //     force_update: false
  //     unit_of_measurement: V
  //     accuracy_decimals: 3
  //     device_class: voltage
  //     state_class: measurement
  //     entity_category: diagnostic
  //   signal_strength:
  //     name: ATC Signal
  //     disabled_by_default: false
  //     id: sensor_sensor_5
  //     force_update: false
  //     unit_of_measurement: dBm
  //     accuracy_decimals: 0
  //     device_class: signal_strength
  //     state_class: measurement
  //     entity_category: diagnostic
  //   id: atc_mithermometer_atcmithermometer
  //   esp32_ble_id: esp32_ble_tracker_esp32bletracker
  atc_mithermometer_atcmithermometer = new atc_mithermometer::ATCMiThermometer();
  atc_mithermometer_atcmithermometer->set_component_source("atc_mithermometer.sensor");
  App.register_component(atc_mithermometer_atcmithermometer);
  esp32_ble_tracker_esp32bletracker->register_listener(atc_mithermometer_atcmithermometer);
  atc_mithermometer_atcmithermometer->set_address(0xA4C138E8DF96ULL);
  sensor_sensor = new sensor::Sensor();
  App.register_sensor(sensor_sensor);
  sensor_sensor->set_name("ATC Temperature");
  sensor_sensor->set_disabled_by_default(false);
  sensor_sensor->set_device_class("temperature");
  sensor_sensor->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  sensor_sensor->set_unit_of_measurement("\302\260C");
  sensor_sensor->set_accuracy_decimals(1);
  sensor_sensor->set_force_update(false);
  atc_mithermometer_atcmithermometer->set_temperature(sensor_sensor);
  sensor_sensor_2 = new sensor::Sensor();
  App.register_sensor(sensor_sensor_2);
  sensor_sensor_2->set_name("ATC Humidity");
  sensor_sensor_2->set_disabled_by_default(false);
  sensor_sensor_2->set_device_class("humidity");
  sensor_sensor_2->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  sensor_sensor_2->set_unit_of_measurement("%");
  sensor_sensor_2->set_accuracy_decimals(0);
  sensor_sensor_2->set_force_update(false);
  atc_mithermometer_atcmithermometer->set_humidity(sensor_sensor_2);
  sensor_sensor_3 = new sensor::Sensor();
  App.register_sensor(sensor_sensor_3);
  sensor_sensor_3->set_name("ATC Battery-Level");
  sensor_sensor_3->set_disabled_by_default(false);
  sensor_sensor_3->set_entity_category(::ENTITY_CATEGORY_DIAGNOSTIC);
  sensor_sensor_3->set_device_class("battery");
  sensor_sensor_3->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  sensor_sensor_3->set_unit_of_measurement("%");
  sensor_sensor_3->set_accuracy_decimals(0);
  sensor_sensor_3->set_force_update(false);
  atc_mithermometer_atcmithermometer->set_battery_level(sensor_sensor_3);
  sensor_sensor_4 = new sensor::Sensor();
  App.register_sensor(sensor_sensor_4);
  sensor_sensor_4->set_name("ATC Battery-Voltage");
  sensor_sensor_4->set_disabled_by_default(false);
  sensor_sensor_4->set_entity_category(::ENTITY_CATEGORY_DIAGNOSTIC);
  sensor_sensor_4->set_device_class("voltage");
  sensor_sensor_4->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  sensor_sensor_4->set_unit_of_measurement("V");
  sensor_sensor_4->set_accuracy_decimals(3);
  sensor_sensor_4->set_force_update(false);
  atc_mithermometer_atcmithermometer->set_battery_voltage(sensor_sensor_4);
  sensor_sensor_5 = new sensor::Sensor();
  App.register_sensor(sensor_sensor_5);
  sensor_sensor_5->set_name("ATC Signal");
  sensor_sensor_5->set_disabled_by_default(false);
  sensor_sensor_5->set_entity_category(::ENTITY_CATEGORY_DIAGNOSTIC);
  sensor_sensor_5->set_device_class("signal_strength");
  sensor_sensor_5->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  sensor_sensor_5->set_unit_of_measurement("dBm");
  sensor_sensor_5->set_accuracy_decimals(0);
  sensor_sensor_5->set_force_update(false);
  atc_mithermometer_atcmithermometer->set_signal_strength(sensor_sensor_5);
  // network:
  //   {}
  // socket:
  //   implementation: bsd_sockets
  // =========== AUTO GENERATED CODE END ============
  App.setup();
}

void loop() {
  App.loop();
}
