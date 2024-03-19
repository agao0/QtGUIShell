#include "gui_start.h"

gui_start::gui_start() {}

void gui_start::drawStartup()
{
    QTextStream qout(stdout);
    qout << "___     _______  _______  __\n";
    qout << "\\\\ \\   // /  _ \\| ____\\ \\/ /\n";
    qout << " \\\\ \\ // /| |_) |  _|  \\  /\n";
    qout << "  \\\\ V/ / |  _ <| |___ /  \\\n";
    qout << "   \\\\__/  |_| \\_\\_____/_/\\_\\\n";
    qout <<"\n";
}

// WIDE V
// QTextStream qout(stdout);
// qout << "___      _______  _______  __\n";
// qout << "\\\\ \\    // /  _ \\| ____\\ \\/ /\n";
// qout << " \\\\ \\  // /| |_) |  _|  \\  /\n";
// qout << "  \\\\ \\// / |  _ <| |___ /  \\\n";
// qout << "   \\\\___/  |_| \\_\\_____/_/\\_\\\n";
// qout <<"\n";

// NARROW V
// QTextStream qout(stdout);
// qout << "___     _______  _______  __\n";
// qout << "\\\\ \\   // /  _ \\| ____\\ \\/ /\n";
// qout << " \\\\ \\ // /| |_) |  _|  \\  /\n";
// qout << "  \\\\ V/ / |  _ <| |___ /  \\\n";
// qout << "   \\\\__/  |_| \\_\\_____/_/\\_\\\n";
// qout <<"\n";
