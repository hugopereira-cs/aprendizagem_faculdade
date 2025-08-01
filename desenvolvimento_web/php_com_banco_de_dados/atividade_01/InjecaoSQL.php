<?php
require_once 'conexao.php';

//realizando uma consulta no BD por meio do login e senha recebidos por POST
$login =$_POST['login'];
$pswd = $_POST['pswd'];
$instrucaoSQL = "Select * From cliente Where login = '$login' And senha = '$pswd'";

try {
    //Execução da consulta
    $resultSet = $dsn->query($instrucaoSQL);
    echo "Consulta realizada com sucesso!<br>";
    //Exibindo os resultados da consulta
    foreach ($resultSet as $row) {
        echo "ID: {$row['id_cliente']} | Nome: {$row['nome_cliente']} | CPF: {$row['cpf_cliente']}";
    }
} catch (PDOException $e) {
	echo 'A conexão falhou e retorno a seguinte mensagem de erro: ' .$e->getMessage();
}

//Realizando uma consulta no BD através do login e senha recebidos por POST
$login = $_POST['login'];
$pswd = $_POST['pswd'];

$stmt = $dsn->prepare("Select * From Usuario Where login = :login And password =:password");
$stmt->execute([':login' => $login, ':password' => $pswd]);

/*Aqui entraria o código para tratar o resultado da instrução SQL acima*/


//Destruindo o objecto statement e fechando a conexão
$stmt = null;
$dsn = null;