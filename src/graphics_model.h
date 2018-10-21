#ifndef HW05_GRAPHICEDITOR_GRAPHICSMODEL_H
#define HW05_GRAPHICEDITOR_GRAPHICSMODEL_H

#include <map>
#include "graphics_types.h"


class GraphicsDocument {    // MODEL
public:
    using GraphicIndex      = std::size_t;
    using GraphicStorage    = std::map<GraphicIndex,GraphicsPtr>;
    using GraphicStoragePtr = std::shared_ptr<GraphicStorage>;

    using CounterType       = std::size_t;

private:
    GraphicStoragePtr   m_graphic_storage;
    CounterType         m_graphics_counter;
    GraphicsPtr         m_selected_graphics;

    Lenght m_width;
    Lenght m_height;

private:
    void            AddGraphics(const GraphicIndex& index, const GraphicsPtr& g) {
        m_graphic_storage->insert(std::make_pair(index,g));
    }

    GraphicIndex    GetNewIndex() {
        GraphicIndex r = GetCounter();
        IncreaseCounter();
        return r;
    }
    CounterType     GetCounter() {
        return m_graphics_counter;
    }
    void            IncreaseCounter() {
        ++m_graphics_counter;
    }

public:
    GraphicsDocument() {
        m_graphic_storage  = std::make_shared<GraphicStorage>(std::initializer_list<GraphicStorage::value_type>{{0, GraphicsPtr(nullptr)}});
        m_graphics_counter = 0;
    }
    ~GraphicsDocument() = default;

    void SetDocumentSize(Lenght x, Lenght y);

    void AddRectangle(const Point& p1, const Point& p2) {
        RectanglePtr rectangle(new Rectangle(p1, p2));
        AddGraphics(GetNewIndex(), rectangle);
    }
    void AddCircle(const Point& c, const Lenght& r) {
        CirclePtr circle(new Circle(c,r));
        AddGraphics(GetNewIndex(), circle);
    }
    void AddLine(const Point& p1, const Point& p2) {
        LinePtr line(new Line(p1,p2));
        AddGraphics(GetNewIndex(), line);
    }

//    template<typename Pointer, typename Type>
//    void AddGraph(const GraphicsData& data) {
//        Pointer pointer(new Type());
//        pointer->LoadData(data);
//        AddGraphics(GetNewIndex(),pointer);
//    };
//
//    void AddRectangle(const GraphicsData& data) {
//        AddGraph<RectanglePtr, Rectangle>(data);
//    }
//    void AddCircle(const GraphicsData& data) {
//        AddGraph<CirclePtr, Circle>(data);
//    }
//    void AddLine(const GraphicsData& data) {
//        AddGraph<LinePtr, Line>(data);
//    }

    void AddLine(const Line& line) {
        LinePtr line_p(new Line(line));
        AddGraphics(GetNewIndex(), line_p);
    }
    void AddCircle(const Circle& circle) {
        CirclePtr circle_p(new Circle(circle));
        AddGraphics(GetNewIndex(), circle_p);
    }
    void AddRectangle(const Rectangle& rectangle) {
        RectanglePtr rectangle_p(new Rectangle(rectangle));
        AddGraphics(GetNewIndex(), rectangle_p);
    }

    const GraphicsPtr& GetGraphics(const GraphicIndex& index) const {
        return m_graphic_storage->at(index);
    }

    const GraphicStoragePtr& GetData() const {
        return m_graphic_storage;
    }

    void Select(const GraphicIndex& index) {
        m_selected_graphics = GetGraphics(index);
    }

    void Remove(const GraphicIndex& index) {
        m_graphic_storage->erase(index);
    }

    void Clear() {
        m_graphic_storage->clear();
        m_graphics_counter = 0;
        m_selected_graphics.reset();
    }
};
using GraphicsDocumentPtr = std::shared_ptr<GraphicsDocument>;

#endif //HW05_GRAPHICEDITOR_GRAPHICSMODEL_H
