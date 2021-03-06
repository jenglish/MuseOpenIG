add_definitions( -DOPENIG_SDK )
set( APP_NAME openig-client-ig )

set( TARGET_SRC_FILES main.cpp )
set( TARGET_OTHER_FILES DataFiles/default.txt DataFiles/openig.xml DataFiles/model/mustang_yellow.osgb.xml DataFiles/model/tire.osgb.xml )

add_executable( ${APP_NAME} ${TARGET_SRC_FILES} ${TARGET_OTHER_FILES} )

include_directories(
	${Boost_INCLUDE_DIRS}	
	${OPENIG_INCLUDE_DIR}	
	${OSG_INCLUDE_DIRS}	
)

target_link_libraries( ${APP_NAME}
    ${OSG_LIBRARIES}
	${OPENIG_LIBRARIES}
    ${Boost_LIBRARIES}
	${OPENGL_LIBRARY}
)

install(
    TARGETS ${APP_NAME}
    RUNTIME DESTINATION bin/openig-client COMPONENT openig-client
)

set_target_properties( ${APP_NAME} PROPERTIES PROJECT_LABEL "Application OpenIG-IG" )

SET(INSTALL_INCDIR include)
SET(INSTALL_BINDIR bin/openig-client)
IF(WIN32)
    SET(INSTALL_LIBDIR bin)
    SET(INSTALL_ARCHIVEDIR lib)
ELSE()
    SET(INSTALL_LIBDIR ${CMAKE_INSTALL_LIBDIR})
    SET(INSTALL_ARCHIVEDIR ${CMAKE_INSTALL_LIBDIR})
ENDIF()

install(FILES ${CMAKE_CURRENT_LIST_DIR}/DataFiles/default.txt DESTINATION ${INSTALL_BINDIR})
install(FILES ${CMAKE_CURRENT_LIST_DIR}/DataFiles/openig.xml DESTINATION ${INSTALL_BINDIR}/igdata/)
install(FILES ${CMAKE_CURRENT_LIST_DIR}/DataFiles/OpenIG-Splash.jpg DESTINATION ${INSTALL_BINDIR}/igdata/)

install(FILES ${CMAKE_CURRENT_LIST_DIR}/DataFiles/model/mustang_yellow.osgb DESTINATION ${INSTALL_BINDIR}/model)
install(FILES ${CMAKE_CURRENT_LIST_DIR}/DataFiles/model/mustang_yellow.osgb.xml DESTINATION ${INSTALL_BINDIR}/model)
install(FILES ${CMAKE_CURRENT_LIST_DIR}/DataFiles/model/tire.osgb DESTINATION ${INSTALL_BINDIR}/model)
install(FILES ${CMAKE_CURRENT_LIST_DIR}/DataFiles/model/tire.osgb.xml DESTINATION ${INSTALL_BINDIR}/model)
