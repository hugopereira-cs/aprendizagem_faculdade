<?php
//...

try {
    $dsn = "pgsql:host=" . HOST . ";port=" . PORT . ";dbname=" . DBNAME;
    $options = array(PDO::ATTR_PERSISTENT => true);

    $pdo = new PDO($dsn, USER, PASSWORD, $options);

} catch (PDOException $e) {
    echo 'A conexão falhou e retornou a seguinte mensagem de erro: ' . $e->getMessage();
}