core = "7.x"
api = "2"

; @todo share42

; Silver CKEditor skin
; @todo: Get this added to http://drupal.org/project/drupalorg_whitelist: http://drupal.org/node/1996744, https://github.com/oleq/silver/issues/2
libraries[silver][download][type] = get
libraries[silver][download][url] = "https://github.com/oleq/silver/archive/master.zip"
libraries[silver][destination] = libraries
libraries[silver][directory_name] = silver
libraries[silver][subdir] = "ckeditor/skins"

; CKEditor plugins
; @todo: Get this added to http://drupal.org/project/drupalorg_whitelist: http://drupal.org/node/1996750
libraries[autogrow][download][type] = get
libraries[autogrow][download][url] = "http://download.ckeditor.com/autogrow/releases/autogrow_4.3.1.zip"
libraries[autogrow][destination] = libraries
libraries[autogrow][directory_name] = autogrow
libraries[autogrow][subdir] = "ckeditor/plugins"
