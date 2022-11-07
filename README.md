# VRESINA-Home-Assistant


![image](https://user-images.githubusercontent.com/51111729/199993999-3fe346de-3849-4f05-8b77-a9b84828e37f.png)


#Docker container stacks:

Home-Assistant:

# HomeAssistant
version: '2'
services:
  homeassistant:
    image: homeassistant/home-assistant:2022.11.1
    container_name: home-assistant
    volumes:
      - /etc/home-assistant/config:/config
      - /etc/localtime:/etc/localtime:ro
      - /etc/letsencrypt:/etc/letsencrypt:ro
    restart: always
#    depends_on:
#      - mosquitto
    network_mode: host

docker-compose file:


ESPHome


Mosquitto
