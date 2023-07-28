/* Bloating Class
 *
 * concrete entity class that extends
 * the abstract Program class
 *
 * The program bloating gets displayed to the user,
 * along with all of its attributes.
 *
 * attributes (inherited from Program):
 *  programName
 *  minutes
 *  seconds
 *  frequency
*/
#ifndef BLOATING_H
#define BLOATING_H
#include"program.h"


class Bloating : public Program
{
public:
    Bloating();
    ~Bloating();
};

#endif // BLOATING_H
