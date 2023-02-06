#pragma once

class MemoryManager
{
    private:
    enum SYSTEMS
    {
        RENDER_S,
        TEXTURE_S
    };
    
    public:
        MemoryManager();
        ~MemoryManager();
};
