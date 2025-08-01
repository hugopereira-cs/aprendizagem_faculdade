<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Teste de Injeção de SQL</title>
</head>
<body>
    <h1>Login</h1>
    <form action="InjectionSQL.php" method="POST">
        <label for="login">Login:</label>
        <input type="text" name="login" id="login" required>
        <br><br>
        
        <label for="pswd">Senha:</label>
        <input type="password" name="pswd" id="pswd" required>
        <br><br>

        <button type="submit">Entrar</button>
    </form>
</body>
</html>