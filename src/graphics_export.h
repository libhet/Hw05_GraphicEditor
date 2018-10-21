#ifndef HW05_GRAPHICEDITOR_IEXPORT_H
#define HW05_GRAPHICEDITOR_IEXPORT_H

#include <string>
#include "graphics_types.h"
#include <iostream>


class IExport {
private:
    std::ostream* m_ostream;

protected:
    virtual GraphicsData ExportPoint(const Point& data) const = 0;
    virtual GraphicsData ExportLine(const Line& data) const = 0;
    virtual GraphicsData ExportCircle(const Circle& data) const = 0;
    virtual GraphicsData ExportRectangle(const Rectangle& data) const = 0;

public:
    explicit IExport(std::ostream& os) : m_ostream{&os} {}
    virtual ~IExport() = default;

    virtual void SavePoint(const Point& data) const {
        *m_ostream << ExportPoint(data);
    }

    virtual void SaveLine(const Line& data) const {
        *m_ostream << ExportLine(data);
    }

    virtual void SaveCircle(const Circle& data) const {
        *m_ostream << ExportCircle(data);
    }

    virtual void SaveRectangle(const Rectangle& data) const {
        *m_ostream << ExportRectangle(data);
    }
};
using ExportPtr = std::shared_ptr<IExport>;

#endif //HW05_GRAPHICEDITOR_IEXPORT_H
