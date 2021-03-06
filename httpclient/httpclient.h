/*
 * @Author: jiejie
 * @Github: https://github.com/jiejieTop
 * @Date: 2019-12-09 21:31:25
 * @LastEditTime: 2020-05-19 08:48:39
 * @Description: the code belongs to jiejie, please keep the author information and source code according to the license.
 */
#ifndef _HTTPCLIENT_H_
#define _HTTPCLIENT_H_

#include <stdio.h>
#include <string.h>

#include "http_parser.h"
#include "http_utils.h"
#include "http_connector.h"
#include "http_url_parser.h"
#include "http_interceptor.h"

#include "http_list.h"
#include "platform_timer.h"
#include "platform_memory.h"
#include "platform_mutex.h"
#include "platform_thread.h"
#include "http_defconfig.h"
#include "network.h"
#include "random.h"
#include "http_error.h"
#include "http_log.h"


typedef struct http_client {
    http_connect_status_t               status;
    http_list_t                         list;
    platform_mutex_t                    global_lock;
    http_interceptor_t                  *interceptor;
    http_connect_params_t               *connect_params;
    uint32_t                            interest_event;
    http_event_t                        *event;
    size_t                              process;
    size_t                              total;
} http_client_t;

int http_client_init(const char *ca);
http_client_t *http_client_lease(void);
void http_client_release(http_client_t *c);
int http_client_get(const char *url, http_event_cb_t cb);
int http_client_post(const char *url, void *data ,http_event_cb_t cb);
void http_client_set_interest_event(http_client_t *c, http_event_type_t event);

#endif /* _HTTPCLIENT_H_ */
