<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title><?= $title ?? 'FomExpress' ?></title>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css" />
    
    <link rel="stylesheet" href="<?= asset('css/global.css') ?>" /> <link rel="preconnect" href="https://fonts.googleapis.com"/>
    <link href="https://fonts.googleapis.com/css2?family=Montserrat:wght@100;400;700&display=swap" rel="stylesheet"/>
</head>
<body>
    <header class="header">
        <div class="logo">
            <img src="<?= asset('images/logo/tecnovidaes.png') ?>">
        </div>
        <nav class="nav">
            <input type="checkbox" id="checkbox" class="checkbox" />
            <label for="checkbox" class="label-menu">
                Menu
                <span class="btnhamburguer"></span>
            </label>
            <ul class="menu">
                <li><a href="<?= url('home') ?>">Home</a></li>
                <li><a href="<?= url('cardapio') ?>">Cardápio</a></li>
                <li><a href="<?= url('quemsomos') ?>">Quem somos</a></li>
                <li><a href="<?= url('espaco') ?>">Nosso espaço</a></li>
            </ul>
        </nav>
    </header>