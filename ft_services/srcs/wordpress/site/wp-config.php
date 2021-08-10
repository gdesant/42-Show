<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'user' );

/** MySQL database password */
define( 'DB_PASSWORD', 'password' );

/** MySQL hostname */
define( 'DB_HOST', 'mysql-service' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         ';YD#!y-F6Ch_+?/hXVkmX@{Zgpa-6`Co[jDZ4CUK-+*f+N`^j}DEQ`+9^ 88^kSi');
define('SECURE_AUTH_KEY',  'r[v/ b-=?~E5H-+j7-sh+1%&|E&v?uD;ApY#H@|#M@Ys$+t/LoR^:ps1>jo|R$Jz');
define('LOGGED_IN_KEY',    'U;df=-FjwBZ&]w<LH2B7~6Qe+#GD`j9?)3($5p0BO|=sGa5#F`P>K^#6x4(@OxcD');
define('NONCE_KEY',        'f][=w|$it^2q 4,G!i/TuBsKH<|A&esFcETv]CT+9MB45X|.eDXc )^L81P8xq.S');
define('AUTH_SALT',        '2vto8{nw+v4%a-|op`bmucB{o1%A|CbEM$rZQcfCDiQIVzO-]xs?cVrw8U8`3cR#');
define('SECURE_AUTH_SALT', '8Q;_K?H!B0-1[VL=vkX6QQR0O?eeec7oA;^0^-h:BJmkrH5}Iqy%rM{J#6B.Xl8H');
define('LOGGED_IN_SALT',   '^-MQ*l@W^-VuoJc-/S}k/7Kuf]KcL@aY%M.7vzT1-V!*UK-WwF$J7,VC_zrIr2.G');
define('NONCE_SALT',       'g|bB-v!E*w`b8YD?i)qd1;$&L22j=b|P+&8mZ8=%2m3|Gj6$1 HR-dKn;c4eh`|-');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';