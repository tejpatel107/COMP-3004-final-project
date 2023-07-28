/* Kidney Class
 *
 * concrete entity class that extends
 * the abstract Program class
 *
 * attributes (inherited from Program):
 *  programName
 *  minutes
 *  seconds
 *  frequency
*/

#ifndef KIDNEY_H
#define KIDNEY_H
#include"program.h"

class Kidney : public Program
{
public:
    Kidney();
    ~Kidney();
};

#endif // KIDNEY_H
