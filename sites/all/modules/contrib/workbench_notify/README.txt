/**
 * @file
 * README file for Workbench Notify.
 */

Workbench Notify

A simple module to automatically notify the section's editors specified
in Workbench Access, on a transition state set in Workbench Moderation.

Features

Workbench Notify enables to automatically notify the editors as previously
specified and individually defined in the Workbench Access's menu
(Editorial assignments by editor) or defined by their role in the
Workbench Access's menu ( Editorial assignments by role), on a transition
state set in Workbench Moderation. For the individually defined editors,
notifications will be sent only to the editors (or users) whose roles are
configured accordingly in the settings of Workbench Notify.

Workbench Notify works with a taxonomy or menu scheme set for Workbench Access.

Purposes

- When a content creator changes the status of a content from “draft” to
“to be reviewed”, a notification is automatically sent to the users who have
been previously assigned in Workbench Access to this content's section and
who have been granted the role of moderator.

- When a editor changes the status of a content from “to be reviewed” to
“published”, a notification is automatically sent to the users who have been
previously assigned in Workbench Access to this content's section, to inform
them that a new content is published.

Two purposes cannot be enabled simultaneously. Only one purpose can be used.
 
Differences with Workbench Email

Workbench Email Provides a way for administrators to define email transitions
and configurable email subject / messages between those transitions. Email
transitions can be defined as when content moves from state to state. Based
on those email transitions, configurable emails can be created/updated/deleted
as the site admin see's fit. Workbench Email presents to the content creators
a list of users that they can email the content updated.

But if you use Workbench Access to assign editors to some specific sections
of the website, the users list presented to the content creator becomes
irrelevant, because the  list contains all the users whose role has been set
accordingly in the email transition, but these users do not necessarily have
the permissions to moderate or edit the content on the specific section where
it has been posted.


How to

- Enable the module.
- Select the transition state for which you want to enable automatic sending
of notifications.
- Select the roles for which the editors will be notified on the transition
state set above. This setting only affects the editors as previously specified
and individually defined in the Workbench Access's menu Editorial assignments
by editor. The editors defined by their role in the Workbench Access's menu
Editorial assignments by role will always be notified.
- Complete the email's fields.
- Enable or disable a confirmation to the content creator. This option
displays a message on the site that confirms the correct sending of the
notifications, and mentions the names of editors who have been duly notified.
