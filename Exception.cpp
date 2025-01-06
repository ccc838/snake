#include "Exception.hpp"


// Réécrivez la méthode `what()` de la classe de base pour retourner la description de l'exception 重写基类的what()方法，返回异常描述
const char* ExceptioneatBody::what() const noexcept {
    return "The snake eat its body";
};


