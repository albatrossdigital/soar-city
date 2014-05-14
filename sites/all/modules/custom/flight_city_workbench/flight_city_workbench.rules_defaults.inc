<?php
/**
 * @file
 * flight_city_workbench.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function flight_city_workbench_default_rules_configuration() {
  $items = array();
  $items['rules_workbench_approved'] = entity_import('rules_config', '{ "rules_workbench_approved" : {
      "LABEL" : "Workbench: Approved",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "workbench_moderation", "rules" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "published" } },
        { "NOT contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "published" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[node:author:mail]",
            "subject" : "Published: [node:title]",
            "message" : "Your post, [node:title], has been published.\\r\\n - To view your post: [node:url]\\r\\n\\r\\nLog message:\\r\\n[node:log]\\r\\n\\r\\n\\r\\n---\\r\\nSent from the baltimorecity.gov automated email system.",
            "from" : "\\u0022City of Baltimore\\u0022 \\u003Cno-reply-workflow@baltimorecity.gov\\u003E",
            "language" : [ "" ]
          }
        },
        { "drupal_message" : { "message" : "An email has been sent to the author informing them that their content has been published." } }
      ]
    }
  }');
  $items['rules_workbench_rejected'] = entity_import('rules_config', '{ "rules_workbench_rejected" : {
      "LABEL" : "Workbench: Rejected",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "workbench_moderation", "rules" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "draft" } },
        { "contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[node:author:mail]",
            "subject" : "Rejected: [node:title]",
            "message" : "Sorry, your post has been rejected: [node:title].\\r\\n - To edit your post: [node:url-edit]\\r\\n\\r\\nLog message:\\r\\n[node:log]\\r\\n\\r\\n\\r\\n---\\r\\nSent from the baltimorecity.gov automated email system.",
            "from" : "\\u0022City of Baltimore\\u0022 \\u003Cno-reply-workflow@baltimorecity.gov\\u003E",
            "language" : [ "" ]
          }
        },
        { "drupal_message" : { "message" : "An email has been sent to the author informing them that their content has been rejected." } }
      ]
    }
  }');
  $items['rules_workbench_request_approval'] = entity_import('rules_config', '{ "rules_workbench_request_approval" : {
      "LABEL" : "Workbench: Request approval",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "workbench_moderation", "flight_city_workbench", "rules" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } }
      ],
      "DO" : [
        { "flight_city_workbench_approvers" : {
            "USING" : { "node" : [ "node" ], "rid" : "5" },
            "PROVIDE" : { "approvers" : { "approvers" : "List of Approvers" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "approvers" ] },
            "ITEM" : { "approver" : "Current approver" },
            "DO" : [
              { "mail" : {
                  "to" : "[approver:mail]",
                  "subject" : "Ready for approval: [node:title]",
                  "message" : "[node:author] has a new post that is ready for approval: [node:title].\\r\\n - To view (and approve): [node:url]\\r\\n - To edit: [node:edit-url]\\r\\n\\r\\nLog message:\\r\\n[node:log]\\r\\n\\r\\n---\\r\\nSent from the baltimorecity.gov automated email system.",
                  "from" : "\\u0022[node:author]\\u0022 \\u003Cno-reply-workflow@baltimorecity.gov\\u003E",
                  "language" : [ "" ]
                }
              }
            ]
          }
        },
        { "drupal_message" : { "message" : "An email requesting approval has been sent to your editor." } }
      ]
    }
  }');
  $items['rules_workbench_request_featured'] = entity_import('rules_config', '{ "rules_workbench_request_featured" : {
      "LABEL" : "Workbench: Request to be featured",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : { "flag_flagged_promote_main" : [] },
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "7" : "7" } },
            "subject" : "Request to be featured: [node:title]",
            "message" : "[node:author] would like [node:title] to be featured on the main site.\\r\\n - To view: [node:url]\\r\\n\\r\\nYou can promote this post in the homepage slideshow, as a quicklink, or as a featured program.\\r\\n\\r\\n---\\r\\nSent from the baltimorecity.gov automated email system.",
            "from" : "\\u0022[node:author]\\u0022 \\u003Cno-reply-workflow@baltimorecity.gov\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_workbench_request_promotion'] = entity_import('rules_config', '{ "rules_workbench_request_promotion" : {
      "LABEL" : "Workbench: Request promotion",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : { "flag_flagged_promote_main" : [] },
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "7" : "7" } },
            "subject" : "Request for promotion: [node:title]",
            "message" : "[node:author] would like you to promote [node:title] to the main site.\\r\\n - To view (and promote): [node:url]\\r\\n - To edit: [node:edit-url]\\r\\n\\r\\n\\r\\nLog message:\\r\\n[node:log]\\r\\n\\r\\n---\\r\\nSent from the baltimorecity.gov automated email system.",
            "from" : "\\u0022[node:author]\\u0022 \\u003Cno-reply-workflow@baltimorecity.gov\\u003E"
          }
        },
        { "drupal_message" : { "message" : "An email requesting promotion has been sent to the citywide site editors." } }
      ]
    }
  }');
  return $items;
}
