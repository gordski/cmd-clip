cmd-clip
========

Simple command repository with direct clipboard access. Replacement for a text file, f***ing about with the mouse/cursors and then cmd-c-alt-tab-cmd-v 

Project Requirements
====================

* Must be easy to set-up. Adding new commands should be done by adding the to a text file.
* Must be quick to paste a command using keyboard.
* Should use system clipboard to maximise comapability with other apps.
* Should support multiple contexts so command lists can be kept short and related to specific activities.
* Should support MacOS and Linux.
* May support Windows.
* May have minimal gui for more complex tasks (i.e. switching context) and feedback (i.e. displaying hints).

File Structure
==============

    ~/.cmd-clip
     |
     +- My Task
        |
        +- clip.txt