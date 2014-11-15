#include "TestDataPopulator.h"
#include <QSignalSpy>
#include <QDebug>

QTEST_MAIN(TestDataPopulator)

/*Cases to Test:
 *    1) Perfect Condition
 *    2) More than 1 "#"
 *    3) No "#"
 *    4) No ascii numbers
 *    5) no emitSignalConnectionSucceeded
 *    6) Invalid chars
 */


