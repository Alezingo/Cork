#include "util/thread_pool.hpp"

#include "cork.hpp"
#include "mesh/mesh.hpp"

namespace Cork
{

    CorkService::~CorkService() { ThreadPool::getPool().Shutdown(); }

    std::unique_ptr<SolidObjectMesh> CorkService::from_triangle_mesh(const TriangleMesh& triangleMesh)
    {
        return (std::unique_ptr<SolidObjectMesh>(new Meshes::Mesh(triangleMesh,SolverControlBlock::get_default_control_block())));
    }

    const SolverControlBlock& SolverControlBlock::get_default_control_block()
    {
        static SolverControlBlock defaultBlock(true, (long)50000, true);

        return (defaultBlock);
    }

}  // namespace Cork
