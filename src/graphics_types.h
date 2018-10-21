#ifndef HW05_GRAPHICEDITOR_GRAPHICS_TYPES_H
#define HW05_GRAPHICEDITOR_GRAPHICS_TYPES_H

#include <memory>

class IImport;
class IExport;

using GraphicsData = std::string;

class Graphics {
public:
    virtual ~Graphics() = default;
    virtual void    LoadData(const IImport& loader, const GraphicsData& data) = 0;
    virtual void    SaveData(const IExport& exporter) const = 0;
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
    float x = 0, y = 0;
public:
    Point() = default;
    Point(float x, float y);
    ~Point() = default;

    void LoadData(const IImport& loader, const GraphicsData& data) override;
    void SaveData(const IExport &exporter) const override;
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

    void LoadData(const IImport &loader, const GraphicsData &data) override;
    void SaveData(const IExport &exporter) const override;
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

    void LoadData(const IImport &loader, const GraphicsData &data) override;
    void SaveData(const IExport &exporter) const override;
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

    void LoadData(const IImport &loader, const GraphicsData &data) override;
    void SaveData(const IExport &exporter) const override;

};
using CirclePtr = std::shared_ptr<Circle>;

#endif //HW05_GRAPHICEDITOR_GRAPHICS_TYPES_H
