//
// Created by cooki on 21.10.2018.
//

#include "graphics_export.h"
#include "graphics_import.h"
#include "graphics_types.h"

void Point::LoadData(const IImport& loader, const GraphicsData& data) {
    loader.AddPoint(data);
}

void Point::SaveData(const IExport &exporter) const {
    exporter.SavePoint(*this);
}

void Line::LoadData(const IImport &loader, const GraphicsData &data) {
    loader.AddLine(data);
}

void Line::SaveData(const IExport &exporter) const {
    exporter.SaveLine(*this);
}

void Rectangle::LoadData(const IImport &loader, const GraphicsData &data) {
    loader.AddRectangle(data);
}

void Rectangle::SaveData(const IExport &exporter) const {
    exporter.SaveRectangle(*this);
}

void Circle::LoadData(const IImport &loader, const GraphicsData &data) {
    loader.AddCircle(data);
}

void Circle::SaveData(const IExport &exporter) const {
    exporter.SaveCircle(*this);
}
