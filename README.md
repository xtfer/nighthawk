# Nighthawk PHP Site Tool

**Version 2.0**
*by Xtfer*

Nighthawk is a lightweight tool for building small PHP sites using flat file structures. It works on any server which can run PHP 8.3+ and has a very low memory footprint. It assumes that all content is held in flat PHP files (not a database), but makes it a little easier to join this content together.

## Features

- **Clean URLs** - SEO-friendly URL structure
- **Generate clean links** - Using the `k()` function
- **Relatively secure** - Modern PHP 8.3+ sanitization
- **Respects folder structures** - Hierarchical content organization
- **Work mostly in HTML** - Use PHP only when required
- **Easy to learn** - Simple, straightforward architecture

## Requirements

- PHP 8.3 or higher
- No database required
- Web server with URL rewriting support (Apache, Nginx, etc.)

## Installation

### Via Composer (Recommended)

```bash
composer create-project xtfer/nighthawk my-site
cd my-site
```

### Manual Installation

1. Clone or download the repository:
```bash
git clone https://github.com/xtfer/nighthawk.git my-site
cd my-site
```

2. Install dependencies (if using Composer):
```bash
composer install
```

3. Configure your web server to point to the project directory.

### Web Server Configuration

#### Apache (.htaccess)

Create a `.htaccess` file in the root directory:

```apache
<IfModule mod_rewrite.c>
    RewriteEngine On
    RewriteBase /

    # Redirect all requests to index.php
    RewriteCond %{REQUEST_FILENAME} !-f
    RewriteCond %{REQUEST_FILENAME} !-d
    RewriteRule ^(.*)$ index.php?q=$1 [L,QSA]
</IfModule>
```

#### Nginx

Add this to your Nginx server block:

```nginx
location / {
    try_files $uri $uri/ /index.php?q=$uri&$args;
}

location ~ \.php$ {
    fastcgi_pass unix:/var/run/php/php8.3-fpm.sock;
    fastcgi_index index.php;
    fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;
    include fastcgi_params;
}
```

## Configuration

Edit `includes/config.inc` to configure your site:

```php
// Site root path (use '/' for root or '/subfolder/' for subdirectory)
define('NH_SITE_ROOT', '/');

// Server URL
define('NH_SERVER', 'http://example.com');

// Home page identifier
define('NH_HOME', 'index');

// Content directory
define('NH_SITE_FOLDER', 'site');

// Enable clean URLs (requires mod_rewrite)
define('NH_CLEAN_URL', TRUE);
```

## Usage

### Creating Pages

Pages are stored in the `site/` directory as PHP files. Each page should set a `$page_title` variable and contain your content.

**Example: `site/index.php`**

```php
<?php
/**
 * Home page
 */

$page_title = 'Home';

?>

<p>Welcome to my Nighthawk site!</p>
```

### Folder Structure

Create subdirectories in `site/` for hierarchical content:

```
site/
├── index.php           (Homepage - example.com/)
├── about/
│   └── index.php      (About page - example.com/about)
├── products/
│   ├── index.php      (Products page - example.com/products)
│   └── item1/
│       └── index.php  (Product item - example.com/products/item1)
```

### Helper Functions

#### `k($destination)` - Generate URLs

```php
// Create a link to a page
<a href="<?php echo k('about'); ?>">About</a>

// Create a link to a nested page
<a href="<?php echo k('products/item1'); ?>">Product 1</a>

// Link to homepage
<a href="<?php echo k('index'); ?>">Home</a>
```

#### `l($destination, $text, $class)` - Generate complete anchor tags

```php
// Simple link
<?php echo l('about', 'About Us'); ?>

// Link with CSS class
<?php echo l('products', 'Our Products', 'nav-link'); ?>
```

#### `check_plain($text)` - Sanitize output

```php
// Sanitize user input or output
echo check_plain($user_input);
```

### Customizing Templates

**Header**: Edit `includes/header.inc` to customize the HTML head and site header.

**Footer**: Edit `includes/footer.inc` to customize the site footer.

**Styles**: Edit `css/main.css` to customize the appearance.

## Project Structure

```
nighthawk/
├── index.php              # Main entry point/router
├── composer.json          # Composer configuration
├── LICENSE                # GPL v3 license
├── README.md              # This file
├── css/
│   └── main.css          # Stylesheet
├── includes/
│   ├── bootstrap.inc     # Core initialization
│   ├── config.inc        # Configuration
│   ├── footer.inc        # Footer template
│   ├── header.inc        # Header template
│   └── util.inc          # Helper functions
└── site/                  # Your content goes here
    ├── index.php         # Homepage
    └── section/
        └── index.php     # Example subpage
```

## Upgrading from Version 1.0

Version 2.0 includes significant updates for PHP 8.3 compatibility:

- Removed deprecated `get_magic_quotes_gpc()` (removed in PHP 5.4)
- Removed deprecated `mysql_real_escape_string()` (removed in PHP 7.0)
- Fixed `define()` calls for PHP 8.0+ compatibility
- Modernized sanitization functions
- Added Composer support

To upgrade, replace the `includes/` directory with the new version and update your `composer.json` if using Composer.

## Credits

The basic Nighthawk setup includes starter files and a version of Eric Meyer's CSS reset by Steve Zeidner ([stevezeidner.com](http://stevezeidner.com/html-and-css-starter-templates)). You can replace the HTML & CSS as you wish.

## License

This software is copyright Christopher Skene and licensed under GPLv3. See the [LICENSE](LICENSE) file for details.

No warranties are provided and you use this software at your own risk.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## Support

For issues and questions, please use the GitHub issue tracker.
