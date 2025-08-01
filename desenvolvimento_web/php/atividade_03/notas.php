<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Boletim Escolar</title>
</head>
<body>
    <?php
    $alunos = array (
        array("João", 8.7, 9.4),
        array("Maria", 9.2, 8.9),
        array("Luis", 7.8, 8.4),
        array("Fernanda", 8.7, 9.1)
    );

    foreach ($alunos as $aluno) {
        echo $aluno[0] . ": P1: " . $aluno[1] . ", P2: " . $aluno[2] . "<br>";
    }
    ?>
</body>
</html>