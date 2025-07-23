import tkinter as tk
from tkinter import messagebox

def comparar_numeros():
    num1 = float(entry_num1.get())
    num2 = float(entry_num2.get())
    if num1 > num2:
        messagebox.showinfo("Resultado", f"O número {num1} é maior que o O número {num2}")
    elif num2 > num1:
        messagebox.showinfo("Resultado", f"O número {num1} é menor que o número {num2}")
    else:
        messagebox.showinfo("Resultado", f"O número {num1} é igual ao O número {num2}")

# Criando a janela
janela = tk.Tk()
janela.title("Maior, Menor ou Igual?")
# Criando os widgets
label_num1 = tk.Label(janela, text="Número 1:")
label_num1.grid(row=0, column=0, padx=10, pady=5, sticky="e")

entry_num1 = tk.Entry(janela)
entry_num1.grid(row=0, column=1, padx=10, pady=5)

label_num2 = tk.Label(janela, text="Número 2:")
label_num2.grid(row=1, column=0, padx=10, pady=5, sticky="e")

entry_num2 = tk.Entry(janela)
entry_num2.grid(row=1, column=1, padx=10, pady=5)

botao_comparar = tk.Button(janela, text="Somar", command=comparar_numeros)
botao_comparar.grid(row=2, columnspan=2, padx=10, pady=5)

# Rodando o loop principal
janela.mainloop()