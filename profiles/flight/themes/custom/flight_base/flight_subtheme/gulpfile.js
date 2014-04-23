// Load plugins
var gulp = require('gulp'),
    gutil = require('gulp-util'),
    compass = require('gulp-compass'),
    jshint = require('gulp-jshint'),
    uglify = require('gulp-uglify'),
    clean = require('gulp-clean'),
    connect = require('gulp-connect'),
    concat = require('gulp-concat'),
    notify = require('gulp-notify'),
    runSequence = require('run-sequence');

var sources = {
  sass: ['sass/**/*.sass'],
  js: ['js/**/*.js', '!js/**/*min.js'],
  clean: ['css/']
};

var destinations = {
  css: 'css/',
  js: 'js/'
};

gulp.task('connect', connect.server({
  root: [sources.css],
  livereload: true,
  open: {
    browser: 'chromium-browser'
  }
}));
 
// Styles
gulp.task('styles', function() {
  return gulp.src(sources.sass)
    .pipe(compass({ 
      config_file: './config.rb', 
      css: 'css',
      sass: 'sass'
    }))
    .pipe(gulp.dest(destinations.css))
    .pipe(connect.reload());
});
 
// Scripts
gulp.task('scripts', function() {
  return gulp.src(sources.js)
    .pipe(jshint('.jshintrc'))
    .pipe(connect.reload());
});
 
// Clean
gulp.task('clean', function() {
  return gulp.src([destinations.css], {read: false})
    .pipe(clean());
});
 
// Default task
gulp.task('build', function() {
  runSequence('clean', ['styles', 'scripts']);
});
 
// Watch
gulp.task('watch', function() {
  // Watch .scss files
  gulp.watch('sass/**/*.sass', ['styles']);
  // Watch .js files
  gulp.watch('js/**/*.js', ['scripts']);
});

gulp.task('default', [
  'build',
  'connect',
  'watch'
]);

