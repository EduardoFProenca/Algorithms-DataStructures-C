<?php
/**
 * Arquivo de Configuração - FomExpress
 * Configurações para XAMPP
 */

// Exibir erros (mudar para false em produção)
error_reporting(E_ALL);
ini_set('display_errors', 1);

// ====================================
// CONFIGURAÇÕES DE AMBIENTE
// ====================================

// Detecta se está no XAMPP ou em produção
$isXampp = (
    strpos($_SERVER['DOCUMENT_ROOT'], 'xampp') !== false || 
    strpos($_SERVER['DOCUMENT_ROOT'], 'htdocs') !== false
);

// ====================================
// CAMINHOS DO PROJETO
// ====================================

if ($isXampp) {
    // Configurações para XAMPP (localhost)
    define('BASE_URL', '/fomexpress/public');
    define('SITE_URL', 'http://localhost/fomexpress/public');
} else {
    // Configurações para produção
    define('BASE_URL', '');
    define('SITE_URL', 'https://seusite.com.br');
}

// Caminhos de pastas
define('BASE_PATH', dirname(dirname(__DIR__)));
define('APP_PATH', BASE_PATH . '/app');
define('PUBLIC_PATH', BASE_PATH . '/public');
define('VIEWS_PATH', APP_PATH . '/Views');

// ====================================
// CONFIGURAÇÕES DO BANCO DE DADOS
// ====================================

define('DB_HOST', 'localhost');
define('DB_NAME', 'fomexpress_db');
define('DB_USER', 'root');
define('DB_PASS', ''); // Vazio no XAMPP
define('DB_CHARSET', 'utf8mb4');

// ====================================
// CONFIGURAÇÕES DA APLICAÇÃO
// ====================================

define('SITE_NAME', 'FomExpress');
define('SITE_DESCRIPTION', 'Qualidade para quem tem pressa');
define('DEFAULT_TIMEZONE', 'America/Sao_Paulo');

// Define timezone
date_default_timezone_set(DEFAULT_TIMEZONE);

// ====================================
// FUNÇÕES AUXILIARES
// ====================================

/**
 * Retorna URL completa de um asset
 * @param string $path Caminho do asset (ex: 'css/home.css')
 * @return string URL completa
 */
function asset($path) {
    return BASE_URL . '/' . ltrim($path, '/');
}

/**
 * Retorna URL de uma rota
 * @param string $route Rota (ex: 'cardapio')
 * @return string URL completa
 */
function url($route = '') {
    if (empty($route) || $route === '/') {
        return BASE_URL;
    }
    return BASE_URL . '/' . ltrim($route, '/');
}

/**
 * Inclui uma view
 * @param string $view Nome da view (ex: 'usuario/cardapio')
 * @param array $data Dados para a view
 */
function view($view, $data = []) {
    extract($data);
    $viewPath = VIEWS_PATH . '/' . str_replace('.', '/', $view) . '.php';
    
    if (file_exists($viewPath)) {
        require $viewPath;
    } else {
        die("View não encontrada: $viewPath");
    }
}

/**
 * Redireciona para outra página
 * @param string $route Rota de destino
 */
function redirect($route) {
    header('Location: ' . url($route));
    exit;
}

// ====================================
// DEBUG (remover em produção)
// ====================================

if ($isXampp) {
    // Mostra informações úteis para debug
    function debug($var, $die = false) {
        echo '<pre style="background:#000;color:#0f0;padding:10px;margin:10px;">';
        var_dump($var);
        echo '</pre>';
        if ($die) die();
    }
}