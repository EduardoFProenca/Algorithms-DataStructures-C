<?php
/**
 * Front Controller - FomExpress
 * Ponto de entrada único da aplicação
 */

// Carrega configurações
require_once __DIR__ . '/../app/Config/config.php';

// Pega a URI requisitada
$request_uri = $_SERVER['REQUEST_URI'];

// Remove o base path da URI (para funcionar no XAMPP)
$uri = str_replace(BASE_URL, '', $request_uri);
$uri = trim(parse_url($uri, PHP_URL_PATH), '/');

// Se estiver vazio, é a home<?php
/**
 * Front Controller - FomExpress
 */

// Carrega configurações
require_once __DIR__ . '/../app/Config/config.php';

// Pega a URI
$request_uri = $_SERVER['REQUEST_URI'];
$uri = str_replace(BASE_URL, '', $request_uri);
$uri = trim(parse_url($uri, PHP_URL_PATH), '/');

// Se vazio, é home
if (empty($uri)) {
    $uri = 'home';
}

// Rotas
$routes = [
    'home' => 'usuario/home.php',
    'cardapio' => 'usuario/cardapio.php',
    'quemsomos' => 'usuario/quemsomos.php',
    'espaco' => 'usuario/espaco.php',
    'resultado' => 'usuario/resultado.php',
];

// Carrega a view
if (array_key_exists($uri, $routes)) {
    $viewFile = VIEWS_PATH . '/' . $routes[$uri];
    
    if (file_exists($viewFile)) {
        require $viewFile;
    } else {
        http_response_code(500);
        echo "Erro: View não encontrada";
    }
} else {
    // 404
    http_response_code(404);
    echo "<h1>404 - Página não encontrada</h1>";
    echo "<p>URI: " . htmlspecialchars($uri) . "</p>";
    echo '<a href="' . url() . '">Voltar para Home</a>';
}
if (empty($uri)) {
    $uri = 'home';
}

// ====================================
// ROTEAMENTO SIMPLES
// ====================================

$routes = [
    'home' => 'home.php',
    'cardapio' => 'usuario/cardapio.php',
    'quemsomos' => 'usuario/quemsomos.php',
    'espaco' => 'usuario/espaco.php',
    'resultado' => 'usuario/resultado.php',
];

// Verifica se a rota existe
if (array_key_exists($uri, $routes)) {
    $viewFile = BASE_PATH . '/app/Views/' . $routes[$uri];
    
    if (file_exists($viewFile)) {
        require $viewFile;
    } else {
        // View não encontrada
        http_response_code(500);
        echo "<h1>Erro 500</h1>";
        echo "<p>Arquivo da view não encontrado: {$routes[$uri]}</p>";
    }
} else {
    // Rota não encontrada - 404
    http_response_code(404);
    ?>
    <!DOCTYPE html>
    <html lang="pt-br">
    <head>
        <meta charset="utf-8">
        <title>404 - Página não encontrada</title>
        <style>
            body {
                font-family: Arial, sans-serif;
                background: #f5f5f5;
                display: flex;
                justify-content: center;
                align-items: center;
                height: 100vh;
                margin: 0;
            }
            .error-box {
                background: white;
                padding: 40px;
                border-radius: 10px;
                box-shadow: 0 2px 10px rgba(0,0,0,0.1);
                text-align: center;
            }
            h1 {
                color: #046f6f;
                font-size: 72px;
                margin: 0;
            }
            p {
                color: #666;
                font-size: 18px;
            }
            a {
                display: inline-block;
                margin-top: 20px;
                padding: 10px 20px;
                background: #046f6f;
                color: white;
                text-decoration: none;
                border-radius: 5px;
            }
            a:hover {
                background: #035858;
            }
            .debug {
                margin-top: 20px;
                padding: 10px;
                background: #f0f0f0;
                border-radius: 5px;
                font-size: 12px;
                color: #666;
            }
        </style>
    </head>
    <body>
        <div class="error-box">
            <h1>404</h1>
            <p>Página não encontrada</p>
            <a href="<?= url() ?>">Voltar para Home</a>
            
            <?php if (defined('BASE_URL') && strpos($_SERVER['DOCUMENT_ROOT'], 'xampp') !== false): ?>
            <div class="debug">
                <strong>Debug Info (apenas em desenvolvimento):</strong><br>
                URI solicitada: <code><?= htmlspecialchars($uri) ?></code><br>
                BASE_URL: <code><?= BASE_URL ?></code><br>
                REQUEST_URI: <code><?= htmlspecialchars($_SERVER['REQUEST_URI']) ?></code>
            </div>
            <?php endif; ?>
        </div>
    </body>
    </html>
    <?php
}