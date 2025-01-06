#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>
#include <exception> 
using namespace std;

// Classe d'exception personnalisée 自定义异常类
class ExceptioneatBody : public exception {
public:
    // Réécrivez la méthode `what()` de la classe de base pour retourner la description de l'exception 重写基类的what()方法，返回异常描述
    const char* what() const throw() override;
};


// Pause 暂停
class Exceptiontouchobstacle : public exception {
public:
    // Réécrivez la méthode `what()` de la classe de base pour retourner la description de l'exception 重写基类的what()方法，返回异常描述
    const char* what() const throw() override;
};


#endif // EXCEPTION_HPP