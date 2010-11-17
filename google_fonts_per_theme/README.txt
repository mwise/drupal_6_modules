About this module
---------

This module allows theme developers to specify google fonts in their theme's .info file.  For more full-featured GFonts support (e.g. admin UI), check out the Google Fonts module (http://drupal.org/project/google_fonts) by BarisW.

How it works:
------------

This module will scan your theme's .info file and selectively load fonts using the Google Font API.

Installation:
------------

1. Download and enable the module as usual
2. Add the following to your theme's hook_preprocess_page call in template.php:


function HOOK_preprocess_page(&$vars, $hook){
	if (module_exists('google_fonts_per_theme')) {
	  _google_fonts_per_theme_page_alter($vars);
	}
	
	... your other code
}


Example usage:
-------------
In your theme's .info file:

fonts[] = 'Crimson Text'
fonts[] = 'Lobster'
fonts[] = 'Nobile'
fonts[] = 'Nobile:b,i,bi'

For in-depth documentation, visit http://code.google.com/apis/webfonts/docs/getting_started.html#Quick_Start
