#ifndef IUI_H
#define IUI_H

/**
 * Interface for User interfaces
 */
class IUI {
protected:
public:
    virtual void Show() = 0;
    virtual void Hide() = 0;
};

#endif