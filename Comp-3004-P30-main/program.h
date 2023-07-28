/* Program Class
 *
 * abstract class
 *
 * A program can be trauma, allergy, kidney or bloating
 *
 * attributes:
 *  programName
 *  minutes
 *  seconds
 *  poweLevel
 *  frequency
 *
 */
#ifndef PROGRAM_H
#define PROGRAM_H
#include <QString>

class Program
{
public:
    Program();
    ~Program();
    QString  programName;
    int minutes;
    int seconds;
    int powerlevel;
    int frequency;
private:


};

#endif // PROGRAM_H
