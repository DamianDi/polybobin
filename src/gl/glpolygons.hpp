#ifndef GLPOLYGONS_HPP
#define GLPOLYGONS_HPP

#include "globject.hpp"
#include "../map/pmsstructs.hpp"
#include <glm/gtc/matrix_transform.hpp>

class GLPolygons: GLObject
{
    public:
        // Parameter should contain info about first vertex of polygon.
        void AddPolygon(PMSVertex firstVertex);

        // \brief Replaces the vertex specified by polygonIndex and vertexIndex with newVertex.
        void EditPolygonVertex(unsigned int polygonIndex, unsigned int vertexIndex,
                               PMSVertex newVertex);

        // \brief clear whole buffer and fill it with polygons
        void ResetPolygons(wxVector<PMSPolygon> polygons);

        unsigned int GetTextureWidth();
        unsigned int GetTextureHeight();

        void Render(glm::mat4 transform);
        void ReplaceTexture(wxString texturesDirectoryPath, wxString textureFilename);
        using GLObject::SetupShaderProgram;
        void SetupShaderProgram();
        void SetupTexture(wxString texturesDirectoryPath, wxString textureFilename);
        void SetupVAO(wxVector<PMSPolygon> polygons);

    private:
        unsigned int m_polygonsCount;
        unsigned int m_textureWidth, m_textureHeight;
        GLuint m_texture, m_vbo;

        static const int GL_POLYGON_VERTEX_SIZE = 9;
        static const int GL_POLYGON_VERTEX_SIZE_BYTES = GL_POLYGON_VERTEX_SIZE * sizeof(GLfloat);
        static const int GL_POLYGON_VERTICES_COUNT = 3;

        void GenerateGLBufferVertices(wxVector<PMSPolygon> &polygons, wxVector<GLfloat> &vertices);
};

#endif