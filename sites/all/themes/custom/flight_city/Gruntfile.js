'use strict';
var path = require('path');
//var lrSnippet = require('grunt-contrib-livereload/lib/utils').livereloadSnippet;

var folderMount = function folderMount(connect, point) {
  return connect.static(path.resolve(point));
};

module.exports = function(grunt) {
  var theme_name = 'flight_subtheme';

  var global_vars = {
    theme_name: theme_name,
    theme_css: 'css',
    theme_scss: 'sass'
  }

  grunt.initConfig({
    global_vars: global_vars,
    pkg: grunt.file.readJSON('package.json'),

    compass: {
      dist: {
        options: {
          config: 'config.rb'
        },
        files: {
          '<%= global_vars.theme_css %>/<%= global_vars.theme_name %>.css': '<%= global_vars.theme_scss %>/<%= global_vars.theme_name %>.<%= global_vars.theme_scss %>'
        }
      }
    },
    watch: {
      grunt: { files: ['Gruntfile.js'] },

      sass: {
        files: '<%= global_vars.theme_scss %>/**/*.<%= global_vars.theme_scss %>',
        tasks: ['compass:dist'],
        options: {
          livereload: true
        }
      },
      js: {
        files: [
          'js/{,**/}*.js',
          '!js/{,**/}*.min.js'
        ],
        tasks: [
          'jshint',
        ]
      }
    },
    jshint: {
      options: {
        jshintrc: '.jshintrc'
      },
      all: [
        'js/{,**/}*.js',
        '!js/{,**/}*.min.js',
        '!js/foundation/{,**/}*.js',
        '!js/vendor/{,**/}*.js'
      ]
    },
    stripmq: {
      options: {
        stripBase: true,
        minWidth: 40,
        maxWidth: 1280
      },
      files: {
        src: [
          'css/custom-foundation.css',
          'css/custom.css',
        ],
        dest: 'css/ie-mq.css'
      },
    }
  });

  //grunt.loadNpmTasks('grunt-sass');
  grunt.loadNpmTasks('grunt-contrib-compass');
  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-stripmq');
  grunt.loadNpmTasks('grunt-contrib-jshint');

  grunt.registerTask('build', ['sass','stripmq']);
  grunt.registerTask('default', ['watch','compass','jshint']);
}