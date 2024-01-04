> A desktop sticky notes application developed in C++ with [Qt-Widget](https://www.qt.io/download-open-source).

![illustration](/home/yinfenglu/Documents/code/projects/sticky-notes/demo-images/illustration.png)

# Background

I quite like the sticky notes application that comes with Windows, but I have failed in finding a similar application for my old laptop running Linux wth Xfce-4 desktop. Therefore, I decided to take this opportunity to sharpen my Qt skills by writing my own desktop sticky notes application! The UI design is (obviously) inspired by the Windows sticky notes application, and the colors are selected from various flavors of the fantastic [catppuccin theme](https://github.com/catppuccin/catppuccin).

This project is currently Work-In-Progress. See [this section](#TO-DO).

# Features

This section lists all the implemented features. For other features I plan to implement later, see [this section](#TO-DO).

- Place the note widgets anywhere on the desktop.

- Pin the note widget on top, great for easy reference.

- Manage all the saved notes in a central panel.

- Hide UI for inactive (unfocused) note widgets. Clean desktop look.

- Modify text font (bold, italic, underline).

- Choose from eight soothing colors.

  ```c++
  #define ROSEWATER "#F4DBD6"
  #define PINK      "#F5C2E7"
  #define GREEN     "#A6E3A1"
  #define SKY       "#BBEAF2"
  #define TEAL      "#94E2D5"
  #define LAVENDER  "#B4BEFE"
  #define YELLOW    "#F8FFAB"
  #define GRAY      "#CDD6F4"
  ```

# TO-DO

This section lists unfinished tasks and additional features I plan to implement later.

- Automatically save notes to a database, so that they can be re-opened later.
- Search for note content.
- Basic settings (e.g. skip dialog before deleting, open all notes from last time at startup) that can be changed in the central panel.
- Option to sort the list in the central panel (by created time, modified time, etc.).
- Drag and re-order the list in the central panel.
- Dark theme for the central panel, and a button to switch between light and dark themes.

# Known issues

I currently don't have solutions for these issues. I will revisit them after I further expand my Qt knowledge.

- When toggling the Always-on-Top option of the note widget, there will be a quick flickering. The cause of this flickering is that the window needs re-rendering after its window flags are updated. Currently, I simply do

  ```c++
  this->setWindowFlags(flags); // update the window flags
  this->show();                // re-render
  ```

  Perhaps double buffering would help. I will need to learn how to implement it.

- On Windows system, minimizing the main window (the notes manager) causes all the notes to disappear. I don't intend to fix this issue, as it works fine on my Xfce-4 desktop.

- Currently, all the note widgets are defined as *Tool widgets* (`Qt::Tool`) to the main window, this means they will be minimized if the main window is minimized. To make the note widgets independent of the main window, the `Qt::Tool` flag needs to be removed, but this gives each note widget its own task-bar tab. I have yet to find a way to achieve both.



