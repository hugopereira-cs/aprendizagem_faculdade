<?php
//Parâmetros utilizados na conexão:
define('HOST', 'localhost');
define('PORT', '5432');
define('DBNAME', 'meudbtest');
define('USER', 'user');
define('PASSWORD', '1234');

try {
    //Estabelecendo conexão:
    $dsn = new PDO("pgsql:host=" . HOST . ";port=" . PORT . "dbname=" . DBNAME, USER, PASSWORD);
    //Mensagem de sucesso na conexão
    echo "Conexão com o banco de dados foi estabelecida com sucesso!<br>";
} catch (PDOException $e) {
    //Captura e exibe o erro em caso de falha
    echo "A conexão falhou e retornou a seguinte mensagem de erro: " . $e->getMessage();
    exit; //Interrompe o script caso a conexão falhe
}
?>