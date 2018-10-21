#include <iostream>


#include "src/graphics_controller.h"
#include "src/graphics_view.h"
#include "src/graphics_model.h"


/// Модель содержит способ хранения данных
/// Добавить, удалить, очистить, созранить, загрузить

/// Контроллер
/// Врапер для модели содержит те же методы и ссылку на модель и вид


/// Вид
/// Содержит ссылку на модель и метод рисования
/// Цикл проходящий по всей модели и вызывающий draw для всех элементов и передающий *this


/// Контроллер соддержит вызовы методов модели и интерфейс к которому обращается View

/// Вид содержит

class DrawModel {
/// Унифицированный интерфейс для вызова методов контроллера

};
using DrawImplPtr = std::shared_ptr<DrawModel>;

class SerializeModel {

};
using SerializeModelPtr = std::shared_ptr<SerializeModel>;


class ConsoleGraphic : public DrawModel {
/// Подогнанный под интерфейс использование какой то конкретной библиотеки
};

/// Контроллер
/// Имеет неизменный интерфейс
/// Подключаетяс какая то модель и вызываются методы этой модели
/// Возможно методы Draw должны принимать указатель на реализацию модели













int main() {
    GraphicsDocumentPtr     model = std::make_shared<GraphicsDocument>();
    GraphicsDocumentViewPtr view  = std::make_shared<GraphicsDocumentView>(model);
    GraphicsDocumentControllerPtr controller = std::make_shared<GraphicsDocumentController>(model,view);

    controller->AddShape(Shape::Rectangle, "sdasdasd ");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}