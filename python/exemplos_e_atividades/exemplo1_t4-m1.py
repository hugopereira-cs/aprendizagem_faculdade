while True:
    temperatura = ler_sensor_temperatura()  # Supomos que esta função leia a temperatura do sensor
    registrar_temperatura(temperatura)     # Supomos que esta função registre a temperatura lida
    time.sleep(60)  # Aguarda 60 segundos antes de ler novamente
    