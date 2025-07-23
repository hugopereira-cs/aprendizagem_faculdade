def regressiva(x):
    if x <= 0:
        print("Acabou")
    else:
        print(x, end=' ')
        regressiva(x-1)

print(regressiva(5))