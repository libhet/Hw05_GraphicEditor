#ifndef HW05_GRAPHICEDITOR_GRAPHICSMODEL_H
#define HW05_GRAPHICEDITOR_GRAPHICSMODEL_H

#include <memory>
#include <map>


using GraphicsData = std::string;

class Graphics {
public:
    virtual ~Graphics() = default;
    virtual void         SetData(const GraphicsData& data) = 0;
    virtual GraphicsData GetData() = 0;
};
using GraphicsPtr = std::shared_ptr<Graphics>;

class Lenght {
private:
    float l;
public:
    Lenght() = default;

    size_t px();
    float  cm();
    float  mm();
};
using LenghtPtr = std::shared_ptr<Lenght>;

class Point : public Graphics {
private:
    float x, y;
public:
    Point() = default;
    Point(float x, float y);
    ~Point() = default;

    void SetData(const GraphicsData& data) override;
    GraphicsData GetData() override;
};
using PointPtr = std::shared_ptr<Point>;

class Line : public Graphics {
private:
    Point p1, p2;
public:
    Line() = default;
    Line(const Point& p1, const Point& p2)
            : p1{p1}, p2{p2}
    {}

    void SetData(const GraphicsData& data) override;
    GraphicsData GetData() override;
};
using LinePtr = std::shared_ptr<Line>;

class Rectangle : public Graphics {
private:
    Point p1,p2;
public:
    Rectangle() = default;
    Rectangle(const Point& p1,const Point& p2)
            : p1{p1}, p2{p2}
    {}

    void SetData(const GraphicsData& data) override;
    GraphicsData GetData() override;
};
using RectanglePtr = std::shared_ptr<Rectangle>;

class Circle : public Graphics {
    Point   center;
    Lenght  radius;
public:
    Circle() = default;
    Circle(const Point& c, const Lenght& r)
            : center{c}, radius{r}
    {}

    void SetData(const GraphicsData& data) override;
    GraphicsData GetData() override;
};
using CirclePtr = std::shared_ptr<Circle>;


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

    template<typename Pointer, typename Type>
    void AddGraph(const GraphicsData& data) {
        Pointer pointer(new Type());
        pointer->SetData(data);
        AddGraphics(GetNewIndex(),pointer);
    };

    void AddRectangle(const GraphicsData& data) {
        AddGraph<RectanglePtr, Rectangle>(data);
    }
    void AddCircle(const GraphicsData& data) {
        AddGraph<CirclePtr, Circle>(data);
    }
    void AddLine(const GraphicsData& data) {
        AddGraph<LinePtr, Line>(data);
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
