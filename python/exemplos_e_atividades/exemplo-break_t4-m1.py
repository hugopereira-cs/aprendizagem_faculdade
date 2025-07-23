while True:
    print('Você está no primeiro laço.')
    opcao1 = str(input('Deseja sair dele? Digite SIM para isso. \n')).upper()
    if opcao1 == 'SIM':
        break  # este break é do primeiro laço
    else:
        while True:
            print('Você está no segundo laço.')
            opcao2 = str(input('Deseja sair dele? Digite SIM para isso. \n')).upper()
            if opcao2 == 'SIM':
               break  # este break é do segundo laço
        print('Você saiu do segundo laço.')
print('Você saiu do primeiro laço')