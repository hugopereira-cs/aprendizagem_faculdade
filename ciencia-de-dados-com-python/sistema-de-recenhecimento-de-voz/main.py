import speech_recognition as sr

# Transsforma a frase falada em texto
# def obter_audio(microfone):
#     with sr.Microphone() as source:
#         microfone.adjust_for_ambient_noise(source)
#         print("Diga alguma coisa: ")
#         audio = microfone.listen(source)
#     return audio

# def transformar_audio_em_texto(microfone, audio):
#     try:
#         frase = microfone.recognize_google(audio, language='pt-BR')
#         return frase
#     except sr.UnknownValueError:
#         print("Não entendi")

# def escutar_microfone():
#     microfone = sr.Recognizer()
#     audio = obter_audio(microfone)
#     texto =  transformar_audio_em_texto(microfone, audio)
#     return texto

# if __name__ == '__main__':
#     texto = escutar_microfone()
#     print("A frase que você disse foi: " + texto)


# Exibindo as palavras de forma tokenizada (separadas
def obter_audio(microfone):
    with sr.Microphone() as source:
        microfone.adjust_for_ambient_noise(source)
        print("Diga alguma coisa: ")
        audio = microfone.listen(source)
    return audio

def transformar_audio_em_texto(microfone, audio):
    try:
        frase = microfone.recognize_google(audio, language='pt-BR')
        return frase.split()  # Tokenização da frase em uma lista de palavras
    except sr.UnknownValueError:
        print("Não foi possível entender o áudio. Por favor, tente novamente.")
        return []

def escutar_microfone():
    microfone = sr.Recognizer()
    audio = obter_audio(microfone)
    palavras = transformar_audio_em_texto(microfone, audio)
    if palavras:
        print("As palavras que você disse foram:")
        print(palavras)

if __name__ == '__main__':
    escutar_microfone()
