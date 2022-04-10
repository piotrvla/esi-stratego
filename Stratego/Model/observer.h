#ifndef OBSERVER_H
#define OBSERVER_H
#include <string>
class Observable;
/**
 * @brief The Observer class
 */
class Observer
{
  public:

    /**
    * @brief update updates the displayed informations according to the modifications that have been done inside the model
    */
    virtual void update(const std::string & propertyName) = 0;
};

#endif // OBSERVER_H
