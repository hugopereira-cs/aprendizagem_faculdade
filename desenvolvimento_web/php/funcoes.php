<?php
function xpto($numero) {
  return $numero % 2 == 0;
}

function abcd($inicio, $fim) {
  for ($i = $inicio; $i <= $fim; $i++) {
    if (xpto($i)) {
      echo $i . " ";
    }
  }
}

abcd(1, 10);
?>