Vandal
======

Vandal is a utility for displaying HTML content as a desktop widget. It can be
used to create a stylish HTML5 clock, show system information, weather forecasts,
or anthing else you can create using HTML, CSS, and JavaScript.

Usage
-----

### Display remote html

    vandal http://example.com/widget.html

### Display a local file

    vandal file:///home/user/widget.html


Recipes
-------

vandal subscribes to the unix philosophy of doing one thing, and doing it well.
As such, vandal does not itself collect or provide any system information to
the widgets it renders.  To access system information, the recommended approach
is to provide a local HTTP API that provides the needed information. Widgets
can then query the local API for information to render, updating themselves
using JavaScript.

Todo
----

* Add option to specify position and size of window
* Add option to specify sticky-ness of window
* Add auto-refresh time option

License
-------

Vandal is licensed under the [GNU GPL v3](https://www.gnu.org/licenses/gpl-3.0.en.html).
