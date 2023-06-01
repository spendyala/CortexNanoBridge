import requests
import socket

endpoint = "192.241.156.85"
device_name = None

def get_ip():
    try:
      endpoint = 'https://ipinfo.io/json'
      response = requests.get(endpoint, verify = True)

      if response.status_code == 200:
        data = response.json()
        IP = data['ip']
      else:
        raise Exception("cannot get global ip")
    except Exception:
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        s.settimeout(0)
        s.connect(('10.254.254.254', 1))
        IP = s.getsockname()[0]
    return IP

def set_name(name=""):
  global device_name
  device_name = name

def heartbeat():
  name = device_name
  ip = get_ip()
  if name is None:
     name = ip
  requests.post(f"http://{endpoint}/heartbeat",
    json={"name": device_name, "ipv4": ip, "dtype": "robot"})