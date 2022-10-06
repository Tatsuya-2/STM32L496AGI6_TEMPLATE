#include "robot.hpp"

Robot::Robot(/* args */)
{
}

Robot::~Robot()
{
}

void Robot::Reboot()
{
  HAL_NVIC_SystemReset();
}

bool Robot::IsMoving()
{
  return jointsStateFlag != 0b1111110;
}

void Robot::SetCommandMode(uint8_t _mode)
{
  commandMode = static_cast<CommandMode>(_mode);
  switch (commandMode)
  {
    case COMMAND_CONTROL_MODE:
      break;
    case SLEEP_MODE:
      break;
    default:
      break;
  }
}

void Robot::Update()
{
  commandHandler.CheckLastCmdUpdate();
}

uint32_t Robot::CommandHandler::Push(const std::string& _cmd)
{
  osStatus_t status = osMessageQueuePut(commandFifo, _cmd.c_str(), 0U, 0U);
  if (status == osOK)
    return osMessageQueueGetSpace(commandFifo);

  return 0xFF;  // failed
}

void Robot::CommandHandler::EmergencyStop()
{
  context->isStopped = true;
  ClearFifo();
}

void Robot::CommandHandler::Resume()
{
  context->isStopped = false;
}

std::string Robot::CommandHandler::Pop(uint32_t timeout)
{
  osStatus_t status = osMessageQueueGet(commandFifo, strBuffer, nullptr, timeout);

  return std::string{ strBuffer };
}

uint32_t Robot::CommandHandler::GetSpace()
{
  return osMessageQueueGetSpace(commandFifo);
}

void Robot::CommandHandler::CheckLastCmdUpdate()
{
  if ((millis() - context->cmd.last_cmd_update) > (context->RATETOMILLIS / context->thresh_last_cmd_update_rate))
  {
    // cmd input state
    context->commandInputState = NO_COMMAND_INPUTTED;
  }
}

uint32_t Robot::CommandHandler::ParseCommand(const std::string& _cmd)
{
  uint8_t argNum;
  char buff1[10] = {};

  switch (context->commandMode)
  {
    case COMMAND_CONTROL_MODE:
      if (_cmd[0] == '>')
      {
      }
      break;
    case SLEEP_MODE:
      break;
  }

  return osMessageQueueGetSpace(commandFifo);
}

void Robot::CommandHandler::ClearFifo()
{
  osMessageQueueReset(commandFifo);
}
