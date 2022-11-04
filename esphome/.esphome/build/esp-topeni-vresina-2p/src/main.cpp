// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.h"
using namespace esphome;
using std::isnan;
using std::min;
using std::max;
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
dallas::DallasComponent *dallas_dallascomponent;
esphome::esp8266::ESP8266GPIOPin *esphome_esp8266_esp8266gpiopin;
dallas::DallasTemperatureSensor *dallas_dallastemperaturesensor;
dht::DHT *dht_dht;
esphome::esp8266::ESP8266GPIOPin *esphome_esp8266_esp8266gpiopin_2;
sensor::Sensor *sensor_sensor;
sensor::Sensor *sensor_sensor_2;
const uint8_t ESPHOME_ESP8266_GPIO_INITIAL_MODE[16] = {INPUT, 255, OUTPUT, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
const uint8_t ESPHOME_ESP8266_GPIO_INITIAL_LEVEL[16] = {255, 255, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
#define yield() esphome::yield()
#define millis() esphome::millis()
#define micros() esphome::micros()
#define delay(x) esphome::delay(x)
#define delayMicroseconds(x) esphome::delayMicroseconds(x)
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="

void setup() {
  // ========== AUTO GENERATED CODE BEGIN ===========
  // esp8266:
  //   board: esp01_1m
  //   framework:
  //     version: 3.0.2
  //     source: ~3.30002.0
  //     platform_version: platformio/espressif8266 @ 3.2.0
  //   restore_from_flash: false
  //   early_pin_init: true
  //   board_flash_mode: dout
  esphome::esp8266::setup_preferences();
  // async_tcp:
  //   {}
  // esphome:
  //   name: esp-topeni-vresina-2p
  //   build_path: .esphome/build/esp-topeni-vresina-2p
  //   platformio_options: {}
  //   includes: []
  //   libraries: []
  //   name_add_mac_suffix: false
  App.pre_setup("esp-topeni-vresina-2p", __DATE__ ", " __TIME__, false);
  // logger:
  //   id: logger_logger
  //   baud_rate: 115200
  //   tx_buffer_size: 512
  //   deassert_rts_dtr: false
  //   hardware_uart: UART0
  //   level: DEBUG
  //   logs: {}
  //   esp8266_store_log_strings_in_flash: true
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
  //   use_address: 192.168.10.248
  //   ap:
  //     ssid: Esp-Topeni-Vresina-2P
  //     password: Pepanek1976!
  //     id: wifi_wifiap_3
  //     ap_timeout: 1min
  //   id: wifi_wificomponent
  //   domain: .local
  //   reboot_timeout: 15min
  //   power_save_mode: NONE
  //   fast_connect: false
  //   output_power: 20.0
  wifi_wificomponent = new wifi::WiFiComponent();
  wifi_wificomponent->set_use_address("192.168.10.248");
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
  wifi::WiFiAP wifi_wifiap_3 = wifi::WiFiAP();
  wifi_wifiap_3.set_ssid("Esp-Topeni-Vresina-2P");
  wifi_wifiap_3.set_password("Pepanek1976!");
  wifi_wificomponent->set_ap(wifi_wifiap_3);
  wifi_wificomponent->set_ap_timeout(60000);
  wifi_wificomponent->set_reboot_timeout(900000);
  wifi_wificomponent->set_power_save_mode(wifi::WIFI_POWER_SAVE_NONE);
  wifi_wificomponent->set_fast_connect(false);
  wifi_wificomponent->set_output_power(20.0f);
  wifi_wificomponent->set_component_source("wifi");
  App.register_component(wifi_wificomponent);
  // mdns:
  //   id: mdns_mdnscomponent
  //   disabled: false
  mdns_mdnscomponent = new mdns::MDNSComponent();
  mdns_mdnscomponent->set_component_source("mdns");
  App.register_component(mdns_mdnscomponent);
  // ota:
  //   password: 626d9537d7ecea7bea902c252602319e
  //   id: ota_otacomponent
  //   safe_mode: true
  //   port: 8266
  //   reboot_timeout: 5min
  //   num_attempts: 10
  ota_otacomponent = new ota::OTAComponent();
  ota_otacomponent->set_port(8266);
  ota_otacomponent->set_auth_password("626d9537d7ecea7bea902c252602319e");
  ota_otacomponent->set_component_source("ota");
  App.register_component(ota_otacomponent);
  if (ota_otacomponent->should_enter_safe_mode(10, 300000)) return;
  // api:
  //   encryption:
  //     key: 0KWtlMXEDU3YMTm406nyyj2T634sJnRFpFdZg5sYJMA=
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
  api_apiserver->set_noise_psk({208, 165, 173, 148, 197, 196, 13, 77, 216, 49, 57, 184, 211, 169, 242, 202, 61, 147, 235, 126, 44, 38, 116, 69, 164, 87, 89, 131, 155, 24, 36, 192});
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
  // dallas:
  //   pin:
  //     number: 2
  //     mode:
  //       output: true
  //       analog: false
  //       input: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     inverted: false
  //     id: esphome_esp8266_esp8266gpiopin
  //   update_interval: 10s
  //   id: dallas_dallascomponent
  dallas_dallascomponent = new dallas::DallasComponent();
  dallas_dallascomponent->set_update_interval(10000);
  dallas_dallascomponent->set_component_source("dallas");
  App.register_component(dallas_dallascomponent);
  esphome_esp8266_esp8266gpiopin = new esphome::esp8266::ESP8266GPIOPin();
  esphome_esp8266_esp8266gpiopin->set_pin(2);
  esphome_esp8266_esp8266gpiopin->set_inverted(false);
  esphome_esp8266_esp8266gpiopin->set_flags(gpio::Flags::FLAG_OUTPUT);
  dallas_dallascomponent->set_pin(esphome_esp8266_esp8266gpiopin);
  // sensor.dallas:
  //   platform: dallas
  //   address: 0x90000072A0EAB28
  //   name: Dallas_2_patro_temp
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
  dallas_dallastemperaturesensor->set_name("Dallas_2_patro_temp");
  dallas_dallastemperaturesensor->set_disabled_by_default(false);
  dallas_dallastemperaturesensor->set_device_class("temperature");
  dallas_dallastemperaturesensor->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  dallas_dallastemperaturesensor->set_unit_of_measurement("\302\260C");
  dallas_dallastemperaturesensor->set_accuracy_decimals(1);
  dallas_dallastemperaturesensor->set_force_update(false);
  dallas_dallastemperaturesensor->set_address(0x90000072A0EAB28);
  dallas_dallastemperaturesensor->set_resolution(12);
  dallas_dallastemperaturesensor->set_parent(dallas_dallascomponent);
  dallas_dallascomponent->register_sensor(dallas_dallastemperaturesensor);
  // sensor.dht:
  //   platform: dht
  //   pin:
  //     number: 0
  //     mode:
  //       input: true
  //       analog: false
  //       output: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     inverted: false
  //     id: esphome_esp8266_esp8266gpiopin_2
  //   model: DHT22
  //   temperature:
  //     name: DHT22_2_patro_temp
  //     disabled_by_default: false
  //     id: sensor_sensor
  //     force_update: false
  //     unit_of_measurement: °C
  //     accuracy_decimals: 1
  //     device_class: temperature
  //     state_class: measurement
  //   humidity:
  //     name: DHT22_2_patro_humidity
  //     disabled_by_default: false
  //     id: sensor_sensor_2
  //     force_update: false
  //     unit_of_measurement: '%'
  //     accuracy_decimals: 0
  //     device_class: humidity
  //     state_class: measurement
  //   update_interval: 10s
  //   id: dht_dht
  dht_dht = new dht::DHT();
  dht_dht->set_update_interval(10000);
  dht_dht->set_component_source("dht.sensor");
  App.register_component(dht_dht);
  esphome_esp8266_esp8266gpiopin_2 = new esphome::esp8266::ESP8266GPIOPin();
  esphome_esp8266_esp8266gpiopin_2->set_pin(0);
  esphome_esp8266_esp8266gpiopin_2->set_inverted(false);
  esphome_esp8266_esp8266gpiopin_2->set_flags(gpio::Flags::FLAG_INPUT);
  dht_dht->set_pin(esphome_esp8266_esp8266gpiopin_2);
  sensor_sensor = new sensor::Sensor();
  App.register_sensor(sensor_sensor);
  sensor_sensor->set_name("DHT22_2_patro_temp");
  sensor_sensor->set_disabled_by_default(false);
  sensor_sensor->set_device_class("temperature");
  sensor_sensor->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  sensor_sensor->set_unit_of_measurement("\302\260C");
  sensor_sensor->set_accuracy_decimals(1);
  sensor_sensor->set_force_update(false);
  dht_dht->set_temperature_sensor(sensor_sensor);
  sensor_sensor_2 = new sensor::Sensor();
  App.register_sensor(sensor_sensor_2);
  sensor_sensor_2->set_name("DHT22_2_patro_humidity");
  sensor_sensor_2->set_disabled_by_default(false);
  sensor_sensor_2->set_device_class("humidity");
  sensor_sensor_2->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  sensor_sensor_2->set_unit_of_measurement("%");
  sensor_sensor_2->set_accuracy_decimals(0);
  sensor_sensor_2->set_force_update(false);
  dht_dht->set_humidity_sensor(sensor_sensor_2);
  dht_dht->set_dht_model(dht::DHT_MODEL_DHT22);
  // socket:
  //   implementation: lwip_tcp
  // network:
  //   {}
  // =========== AUTO GENERATED CODE END ============
  App.setup();
}

void loop() {
  App.loop();
}
