// Load plugins
var gulp = require('gulp'),
    compass = require('gulp-compass'),
    minifycss = require('gulp-minify-css'),
    jshint = require('gulp-jshint'),
    uglify = require('gulp-uglify'),
    rename = require('gulp-rename'),
    clean = require('gulp-clean'),
    concat = require('gulp-concat'),
    notify = require('gulp-notify'),
    cache = require('gulp-cache'),
    livereload = require('gulp-livereload'),
    lr = require('tiny-lr'),
    server = lr();
 
// Styles
gulp.task('styles', function() {
  return gulp.src(['sass/**/*.sass'])
    .pipe(compass({ 
      config_file: './config.rb', 
      css: 'css',
      sass: 'sass'
    }))
    .pipe(gulp.dest('css'))
    .pipe(livereload(server))
    .pipe(notify({ message: 'Styles task complete' }));
});
 
// Scripts
gulp.task('scripts', function() {
  return gulp.src(['js/**/*.js', '!js/**/*min.js'])
    .pipe(jshint('.jshintrc'))
    .pipe(notify({ message: 'Scripts task complete' }));
});
 
// Clean
gulp.task('clean', function() {
  return gulp.src(['dist/styles', 'dist/scripts', 'dist/images'], {read: false})
    .pipe(clean());
});
 
// Default task
gulp.task('default', [], function() {
    gulp.start('styles', 'scripts');
});
 
// Watch
gulp.task('watch', function() {
 
  // Listen on port 35729
  server.listen(35729, function (err) {
    if (err) {
      return console.log(err)
    };
 
    // Watch .scss files
    gulp.watch('sass/**/*.sass', ['styles']).pipe;
 
    // Watch .js files
    gulp.watch('js/**/*.js', ['scripts']);
 
  });
 
});