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
        tasks: ['compass:dist', 'stripmq', 'replace:ieRem', 'replace:ieRemMain','copy:ie'],
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
      },
      images: {
        files: 'images/src/{,**/}*.png',
        tasks: ['imagemin']
      },
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
    },
    replace: {
      ieRem: {
        src: [
          'css/ie-mq.css'
        ],
        overwrite: true,
        replacements: [{
          from: /(\d*\.?\d+)rem/ig,
          to: function(matchedWord, index, fullText, regexMatches) {
            var val = regexMatches.pop();
            return parseFloat(val) * 14 + "px";
          }
        }]
      },
      ieRemMain: {
        src: [
          'css/custom*.css'
        ],
        dest: 'css/ie/',
        replacements: [{
          from: /(\d*\.?\d+)rem/ig,
          to: function(matchedWord, index, fullText, regexMatches) {
            var val = regexMatches.pop();
            return parseFloat(val) * 14 + "px";
          }
        }]
      }
    },
    copy: {
      ie: {
        expand: true,
        cwd: 'css/ie',
        src: [
          'custom*.css', '!*-ie.css'
        ],
        dest: 'css/ie/',
        ext: '-ie.css'
      }
    },
    buildIcons: {
       options: {
        processors: [
          {
            pattern: /asdas/gi,
            handler: function(context, matchParams) {
                return 'img="static/path/to/image.png"';
            }
          }
        ]
      },
      files: [
        {
          src: 'css/fontawesome-icons.css',
          dest: 'documentation/dist/icons/icons-fontawesome.html'
        }
      ]
    },
    imagemin: {
      options: {                       // Target options
        optimizationLevel: 3
      },
      dynamic: {                         // Another target
        files: [{
          expand: true,                  // Enable dynamic expansion
          cwd: 'images/src/',                   // Src matches are relative to this path
          src: ['**/*.png'],             // Actual patterns to match
          dest: 'images/'                  // Destination path prefix
        }]
      }
    },
    copyIcons: {
      files: [
        {
          src: 'css/fontawesome-icons.css',
          dest: 'documentation/dist/icons/css/'
        }
      ]
    }
  });

  //grunt.loadNpmTasks('grunt-sass');
  grunt.loadNpmTasks('grunt-contrib-compass');
  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-contrib-copy');
  grunt.loadNpmTasks('grunt-text-replace');
  grunt.loadNpmTasks('grunt-stripmq');
  grunt.loadNpmTasks('grunt-contrib-jshint');
  grunt.loadNpmTasks('grunt-newer');
  grunt.loadNpmTasks('grunt-contrib-imagemin');

  grunt.registerTask('build', ['compass'/*, 'imagemin'*/,'stripmq', 'replace:ieRem', 'replace:ieRemMain', 'copy:ie']);
  grunt.registerTask('icons', ['compass', 'buildIcons', 'copyIcons']);
  grunt.registerTask('default', ['watch','compass','jshint']);
}
