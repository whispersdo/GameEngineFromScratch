#include "IPipelineStateManager.hpp"
#include <map>

namespace My {
    class PipelineStateManager : implements IPipelineStateManager
    {
        public:
            PipelineStateManager() = default;
            virtual ~PipelineStateManager();

            int Initialize() override;
            void Finalize() override {}
            void Tick() override {}

            bool RegisterPipelineState(PipelineState& pipelineState) override;
            void UnregisterPipelineState(PipelineState& pipelineState) override;
            void Clear() override;

            const std::shared_ptr<PipelineState> GetPipelineState(std::string name) const final;

        protected:
            virtual bool InitializePipelineState(PipelineState** ppPipelineState) = 0;
            virtual void DestroyPipelineState(PipelineState& pipelineState) = 0;

        protected:
            std::map<std::string, std::shared_ptr<PipelineState>> m_pipelineStates;
    };
}
