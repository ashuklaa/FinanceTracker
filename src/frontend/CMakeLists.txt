set(FRONTEND_SOURCES main.cpp mainwindow.cpp mainwindow.ui)

add_executable(${PROJECT_NAME} ${FRONTEND_SOURCES} ${RESOURCE_FILES})

set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES AUTOMOC ON
             AUTOUIC ON
             AUTORCC ON)

target_link_libraries(${PROJECT_NAME} Qt6::Widgets)
