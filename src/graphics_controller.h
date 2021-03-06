#ifndef HW05_GRAPHICEDITOR_GRAPHICSCONTROLLER_H
#define HW05_GRAPHICEDITOR_GRAPHICSCONTROLLER_H

#include "graphics_model.h"

enum class Shape {
    Line,
    Circle,
    Rectangle
};

class GraphicsDocumentController {  //CONTROLLER
public:
    using ShapeSelector = GraphicsDocument::GraphicIndex ;
private:
    GraphicsDocumentPtr         m_model;

public:
    GraphicsDocumentController(const GraphicsDocumentPtr& model)
            : m_model(model) {}

    void SelectShape(const ShapeSelector& selector) {
        m_model->Select(selector);
    }

    void UpdateView() {
        m_model->UpdateView();
    }

    void AddShape(Shape shape, const GraphicsData& data) {
        switch(shape) {
            case Shape::Line :
                m_model->AddLine(data);
                break;
            case Shape::Circle :
                m_model->AddCircle(data);
                break;
            case Shape::Rectangle :
                m_model->AddRectangle(data);
                break;
        }
        UpdateView();
    }

    void RemoveShape(const ShapeSelector& selector) {
        m_model->Remove(selector);
        UpdateView();
    }

    bool Import();
    bool Export();

};
using GraphicsDocumentControllerPtr = std::shared_ptr<GraphicsDocumentController>;

#endif //HW05_GRAPHICEDITOR_GRAPHICSCONTROLLER_H
