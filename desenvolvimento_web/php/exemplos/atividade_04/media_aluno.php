<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Media Aluno</title>
</head>
<body>
    <?php
    //Definição do array que contém os dados do aluno
    $aluno = array("João", 8.8, 9.4);

    //Implementando a função para calcular a média
    function calc_media($n1, $n2) {
        return ($n1 + $n2) / 2;
    }

    $media = calc_media($aluno[1], $aluno[2]);

    //Imprimindo os dados na tela
    echo $aluno[0]." tem média igual a ".$media;

    ?>
</body>
</html>